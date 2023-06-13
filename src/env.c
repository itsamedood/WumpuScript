#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "env.h"
#include "out.h"

int loadenv(char *path)
{
	FILE *dotenv = fopen(path, "r");
	if (!dotenv) raise("'.env' does not exist.", 1);

	char line[MAX_LINE_LENGTH];
	while (fgets(line, sizeof(line), dotenv) != NULL)
	{
		char *trimmed = strtok(line, "\n");
		trimmed = strtok(trimmed, "\r");
		trimmed = strtok(trimmed, "\t");

		if (trimmed == NULL || trimmed[0] == '#' || trimmed[0] == '\0') continue;

		char *key = strtok(trimmed, "=");
		char *value = strtok(NULL, "=");

		if (key != NULL && value != NULL)
		{
			int result = setenv(key, value, 1);
			if (result != 0) raise("failed to set environmental variable.", 1);
		} else raise("key or value found null.", 1);
	}

	char *token = getenv("TOKEN");
	printf("TOKEN = %s\n", token);

	fclose(dotenv);
	return 0;
}
