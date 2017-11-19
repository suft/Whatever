#pragma once

#if defined(BUILD_Debug)
#define DEBUGGING          true
#elif defined(BUILD_Release)
#define DEBUGGING          false
#endif

#define WIDTH               1920
#define HEIGHT              1080
#define DIMENSIONS          sf::Vector2f(1920, 1080)
#define ORIGIN              sf::Vector2f(0, 0)
