#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "env.h"

void loadenv()
{
	/* Construct path to .env. */
	char *pwd = getenv("PWD");
	char path[256];
	snprintf(path, sizeof(path), "%s/.env", pwd);

	FILE *dotenv = fopen(path, "r");
	if (!dotenv) exit(1);
	/* ... */
	if (fclose(dotenv) != 0) exit(1);
}
