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

	/* Find size of file. */
	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	rewind(file);

	/* Allocate memory for string. */
	char *content = (char*)malloc((file_size+1) * sizeof(char));
	if (!content) raise(1, "failed to allocate memory for file content.");

	/* Read file content into string. */
	size_t read_size = fread(content, sizeof(char), file_size, file);
	if (read_size != file_size)
	{
		fclose(file);
		free(content);
		raise(1, "failed to read '%s'.", path);
	}

	content[file_size] = '\0';
	fclose(file);

	return content;
}
