#pragma once

#include <cmath>
#include <map>
#include <functional>

constexpr float pi = 3.14159265358979323846f;
typedef std::function<float(float, float, float, float)> penner;

enum class Function { Linear, Sine, Cubic, Exponential, Count};
enum class Type { In, Out, InOut, Count};

class Linear {
public:
    inline static float easeNone(float t, float b, float c, float d) {
        return c*t/d + b;
    }

    inline static float easeIn(float t, float b, float c, float d) {
        return c*t/d + b;
    }

    inline static float easeOut(float t, float b, float c, float d) {
        return c*t/d + b;
    }

    inline static float easeInOut(float t, float b, float c, float d) {
        return c*t/d + b;
    }
};

class Sine {
public:
    inline static float easeIn(float t, float b, float c, float d) {
        return -c * cos(t/d * (float(pi)/2)) + c + b;
    }

    inline static float easeOut(float t, float b, float c, float d) {
        return c * sin(t/d * (float(pi)/2)) + b;
    }

    inline static float easeInOut(float t, float b, float c, float d) {
        return -c/2 * (cos(float(pi)*t/d) - 1) + b;
    }
};

class Cubic {
public:
    inline static float easeIn(float t, float b, float c, float d) {
        return c*(t/=d)*t*t + b;
    }

    inline static float easeOut(float t, float b, float c, float d) {
        return c*((t=t/d-1)*t*t + 1) + b;
    }

    inline static float easeInOut(float t, float b, float c, float d) {
        if ((t/=d/2) < 1) return c/2*t*t*t + b;
        return c/2*((t-=2)*t*t + 2) + b;
    }
};

class Exponential {
public:
    inline static float easeIn(float t, float b, float c, float d) {
        return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
    }

    inline static float easeOut(float t, float b, float c, float d) {
        return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
    }

    inline static float easeInOut(float t, float b, float c, float d) {
        if (t==0) return b;
        if (t==d) return b+c;
        if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
        return c/2 * (-pow(2, -10 * --t) + 2) + b;
    }
};

inline penner easing(Function f, Type t) {
    static std::map<std::pair<Function, Type>, penner> index = {
        {std::make_pair(Function::Linear, Type::In), Linear::easeIn},
        {std::make_pair(Function::Linear, Type::Out), Linear::easeOut},
        {std::make_pair(Function::Linear, Type::InOut), Linear::easeInOut},

        {std::make_pair(Function::Sine, Type::In), Sine::easeIn},
        {std::make_pair(Function::Sine, Type::Out), Sine::easeOut},
        {std::make_pair(Function::Sine, Type::InOut), Sine::easeInOut},

        {std::make_pair(Function::Cubic, Type::In), Cubic::easeIn},
        {std::make_pair(Function::Cubic, Type::Out), Cubic::easeOut},
        {std::make_pair(Function::Cubic, Type::InOut), Cubic::easeInOut},

        {std::make_pair(Function::Exponential, Type::In), Exponential::easeIn},
        {std::make_pair(Function::Exponential, Type::Out), Exponential::easeOut},
        {std::make_pair(Function::Exponential, Type::InOut), Exponential::easeInOut},
    };

    return index[std::make_pair(f, t)];
}
