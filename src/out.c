#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "out.h"

void raise(int code, const char *format, ...)
{
	char buffer[500];
	char message[500];

	snprintf(message, sizeof(message), "wmps: %serror%s: %s", PRST_ERROR, PRST_RESET, format);

	va_list args;
	va_start(args, format);

	vsnprintf(buffer, sizeof(buffer), message, args);
	va_end(args);

	printf("%s\n", buffer);
	exit(code);
}
