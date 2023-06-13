#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cli.h"
#include "env.h"
#include "out.h"

void print_help()
{
	char *help[] = {
		"Usage: wmps [flags] <main> [...]",
		"Flags:",
		"╭─ --help",
		"⏐  --verbose",
		"╰─ --version",
		NULL
	};

	for (int i = 0; help[i] != NULL; i++) printf("%s\n", help[i]);
	exit(0);
}

void print_version()
{
	char *version = "0.0.1";
	char version_text[50];

	snprintf(version_text, sizeof(version_text), "Version: %s%s%s", STYLE_LIGHT, version, PRST_RESET);
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

	/* Construct path to .env. */
	char *pwd = getenv("PWD");
	char path[256];
	snprintf(path, sizeof(path), "%s/.env", pwd);

	loadenv(path);

	const char *main = argv[argc-1];
	if (main[0] == '-') raise("missing argument '<main>'.", 1);
}
