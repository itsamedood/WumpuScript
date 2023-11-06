#include <stdio.h>
#include "cli.h"
#include "main.h"
#include "out.h"

int main(int argc, const char *argv[])
{
  #if !defined(WINDOWS) && !defined(UNIX)
  raise(1, "unknown OS.");
  #endif

  process_args(argc, argv);
  return 0;
}
