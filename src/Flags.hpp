#pragma once
#include <iostream>

#if defined(BUILD_Debug)
#define DEBUGGING          true
#elif defined(BUILD_Release)
#define DEBUGGING          false
#endif

#define WIDTH               1920
#define HEIGHT              1080