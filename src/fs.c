#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fs.h"
#include "out.h"

int exists(char *path) { return access(path, F_OK); }

char *read_file(const char *path)
{
	FILE *file = fopen(path, "r");
	if (!file) raise(1, "failed to open file: '%s'.", path);

	/* need to finish lol */

	return "HERE ARE SOME FUCKING THINGS TO TOKENIZE FFS";
}
