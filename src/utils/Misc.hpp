#pragma once

#include <algorithm>

template<class T>
const T& clamp(const T& x, const T& lower, const T& upper) {
    return std::min(upper, std::max(x, lower));
}
