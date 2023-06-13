#ifndef MAIN_H
#define MAIN_H

#if defined(__unix__) || defined(__APPLE__)
#define UNIX 1
#define WINDOWS 0
#elif defined(_MSC_VER)
#define UNIX 0
#define WINDOWS 1
#endif

#endif
