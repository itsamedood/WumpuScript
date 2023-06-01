#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cli.h"
#include "out.h"

static void print_help()
{
	char *help[] = {
		"Usage: wmps [flags] <main> [...]",
		"Flags:",
		"╭─ --help",
		"⏐  --verbose",
		"╰─ --version",
		NULL,
	};

	for (int i = 0; help[i] != NULL; i++) printf("%s\n", help[i]);
}

static void print_version()
{
	char *version = "0.0.1";
	char version_text[50];

	snprintf(version_text, sizeof(version_text), "Version: %s%s%s", STYLE_LIGHT, version, PRST_RESET);
	printf("%s\n", version_text);
}

void process_args(int argc, const char *argv[])
{
	if (argc < 2) print_help();
	else
		for (int i = 0; i < argc; i++)
		{
			if (strcmp(argv[i], "--help") == 0) print_help();
			if (strcmp(argv[i], "--verbose") == 0 ) { }
			if (strcmp(argv[i], "--version") == 0 ) print_version();
		}
}
