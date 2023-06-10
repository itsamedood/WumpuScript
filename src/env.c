#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "env.h"
#include "out.h"

void loadenv()
{
	/* Construct path to .env. */
	char *pwd = getenv("PWD");
	char path[256];
	snprintf(path, sizeof(path), "%s/.env", pwd);

	FILE *dotenv = fopen(path, "r");
	if (!dotenv) raise("'.env' does not exist.", 1);

	char line[500];
	while (fgets(line, sizeof(line), dotenv) != NULL)
	{
		printf("Line: %s\n", line);
	}

	if (fclose(dotenv) != 0) raise("failed to close '.env'.", 1);
}
