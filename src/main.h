#ifndef MAIN_H
#define MAIN_H

#if defined(__unix__) || defined(__APPLE__)
#define UNIX 1
#endif /* Linux || MacOS */
#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS 1
#endif /* Windows */

#define WMPS_VERSION "0.0.1-alpha"

#endif
