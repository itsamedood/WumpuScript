#include <stdlib.h>
#include "parser.h"
#include "tokens.h"

void parse_tokens(enum Token *tokens, size_t tokencount)
{
	for (int i = 0; i < (int)tokencount; i++)
	{
		enum Token token = tokens[i];
		switch (token)
		{
			case LETTER: break;
			case NUMBER: break;
		}
	}
}
