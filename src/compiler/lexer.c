#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "tokens.h"

enum Token *tokenize(char *code)
{
	enum Token *tokens = malloc(strlen(code)+1 * sizeof(char));

	for (int i = 0; i < (int)strlen(code); i++)
	{
		char cc = code[i];
		printf("CC = %c\n", cc);
	}

	return tokens;
}
