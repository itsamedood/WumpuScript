#include <stdio.h>
#include <stdlib.h>
#include "out.h"

void raise(char *message, int code)
{
	printf("wmps: %serror%s: %s\n", PRST_ERROR, PRST_RESET, message);
	exit(code);
}
