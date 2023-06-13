#ifndef ENV_H
#define ENV_H

#define MAX_LINE_LENGTH 300

/* Loads variables from `$PWD/.env`. */
int loadenv(char *path);
#endif
