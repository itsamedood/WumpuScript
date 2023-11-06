#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "compiler/lexer.h"
#include "cli.h"
#include "env.h"
#include "fs.h"
#include "main.h"
#include "out.h"

void print_help()
{
  char *help[] = {
    "Usage: wmps [flags] <main> [...]",
    "Flags:",
    #ifdef UNIX
    "╭─ --help",
    "⏐  --verbose",
    "╰─ --version",
    #else
    "  --help",
    "  --verbose",
    "  --version",
    #endif
    NULL
  };

  for (int i = 0; help[i] != NULL; i++) printf("%s\n", help[i]);
  exit(0);
}

void print_version()
{
  char version_text[50];

  snprintf(version_text, sizeof(version_text), "Version: %s%s%s", STYLE_LIGHT, WMPS_VERSION, PRST_RESET);
  printf("%s\n", version_text);
  exit(0);
}

void process_args(int argc, const char *argv[])
{
  if (argc < 2) print_help();
  else
    for (int i = 0; i < argc; i++)
    {
      if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) print_help();
      if (strcmp(argv[i], "--verbose") == 0 || strcmp(argv[i], "-vb") == 0) { }
      if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0 ) print_version();
    }

  // Construct path to `.env`.
  #ifdef WINDOWS
  char pwd[500];
  GetCurrentDirectoryA(500, pwd);
  #else
  char *pwd = getenv("PWD");
  #endif
  char path[256];
  snprintf(path, sizeof(path), "%s/.env", pwd);

  loadenv(path);
  path[0] = '\0'; // Reset buffer.

  const char *mainfile = argv[argc-1];
  if (mainfile[0] == '-') raise(1, "missing argument '<main>'.");

  snprintf(path, sizeof(path), "%s/%s", pwd, mainfile);
  printf("PATH = %s\n", path);

  if (exists(path) != 0) raise(1, "could not find '%s'.", path);

  // Invoke compiler; Lexer (tokenize) -> Parser (parse)
  char *mainfilecontent = read_file(path);
  enum Token *tokens = tokenize(mainfilecontent);

  free(tokens);
}
