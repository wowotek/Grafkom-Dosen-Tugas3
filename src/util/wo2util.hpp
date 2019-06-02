#ifndef WO2UTIL_HPP
#define WO2UTIL_HPP

#include <vector>

template <typename T> struct tvec2{
    T x, y;

    tvec2(void) = default;
    tvec2(T s): x(s), y(s) {}
    tvec2(T x, T y): x(x), y(y) {}

    void operator+=(tvec2<T> other){
        x += other.x;
        y += other.y;
    }

    void operator-=(tvec2<T> other){
        x -= other.x;
        y -= other.y;
    }

    void operator*=(tvec2<T> other){
        x *= other.x;
        y *= other.y;
    }

    void operator/=(tvec2<T> other){
        x /= other.x;
        y /= other.y;
    }

    tvec2<T> operator+(tvec2<T> other){
        return tvec2<T>(x + other.x, y + other.y);
    }

    tvec2<T> operator-(tvec2<T> other){
        return tvec2<T>(x - other.x, y - other.y);
    }

    tvec2<T> operator*(tvec2<T> other){
        return tvec2<T>(x * other.x, y * other.y);
    }

    tvec2<T> operator/(tvec2<T> other){
        return tvec2<T>(x / other.x, y / other.y);
    }

    tvec2<T> operator+(T other){
        return tvec2<T>(x + other, y + other);
    }

    tvec2<T> operator-(T other){
        return tvec2<T>(x - other, y - other);
    }

    tvec2<T> operator*(T other){
        return tvec2<T>(x * other, y * other);
    }

    tvec2<T> operator/(T other){
        return tvec2<T>(x / other, y / other);
    }
};

template <typename T>
tvec2<T> operator+(T a, tvec2<T> b)
{
    return tvec2<T>(a + b.x, a + b.y);
}

template <typename T>
tvec2<T> operator-(T a, tvec2<T> b)
{
    return tvec2<T>(a - b.x, a - b.y);
}

template <typename T>
tvec2<T> operator*(T a, tvec2<T> b)
{
    return tvec2<T>(a * b.x, a * b.y);
}

template <typename T>
tvec2<T> operator/(T a, tvec2<T> b)
{
    return tvec2<T>(a / b.x, a / b.y);
}

template <typename T>
T length(tvec2<T> v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

template <typename T>
tvec2<T> normalize (tvec2<T> v)
{
    return v / length(v);
}

template <typename T>
T distance (tvec2<T> a, tvec2<T> b)
{
    return length(a - b);
}

typedef tvec2<GLfloat> vec2f;
typedef tvec2<GLint> vec2i;
typedef tvec2<GLdouble> vec2d;

#define TO_FPS(FPS_VALUE) 1000/FPS_VALUE
#define randint(min, max) std::rand() % max + min

#endif