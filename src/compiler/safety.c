#include <stdio.h>
#include "safety.h"
#include "../fs.h"
#include "../out.h"

int validate_require(char *required) { return exists(required); }
