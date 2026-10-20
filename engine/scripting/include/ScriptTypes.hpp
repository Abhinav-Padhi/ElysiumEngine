#pragma once

#include "CoreMath.hpp"
#include <cstdint>
#include <cmath>

namespace Elysium {

/**
 * @struct Vector2
 * @brief Represents a 2D vector.
 */
struct Vector2 {
    float x = 0.0f;
    float y = 0.0f;

    Vector2() = default;
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2(const Vec3& v) : x(v.x), y(v.y) {}

    Vector2 operator+(const Vector2& o) const { return {x + o.x, y + o.y}; }
    Vector2 operator-(const Vector2& o) const { return {x - o.x, y - o.y}; }
    Vector2 operator*(float scalar)     const { return {x * scalar, y * scalar}; }
    Vector2 operator/(float scalar)     const {
        return (scalar != 0.0f) ? Vector2{x / scalar, y / scalar} : Vector2{0.0f, 0.0f};
    }

    Vector2& operator+=(const Vector2& o) { x += o.x; y += o.y; return *this; }
    Vector2& operator-=(const Vector2& o) { x -= o.x; y -= o.y; return *this; }
    Vector2& operator*=(float scalar)     { x *= scalar; y *= scalar; return *this; }

    bool operator==(const Vector2& o) const { return x == o.x && y == o.y; }
    bool operator!=(const Vector2& o) const { return !(*this == o); }

    float MagnitudeSquared() const { return x * x + y * y; }
    float Magnitude() const        { return std::sqrt(MagnitudeSquared()); }

    Vector2 Normalized() const {
        float m = Magnitude();
        return (m > 0.0f) ? Vector2{x / m, y / m} : Vector2{0.0f, 0.0f};
    }

    float Dot(const Vector2& o) const { return x * o.x + y * o.y; }
    float DistanceTo(const Vector2& o) const { return (*this - o).Magnitude(); }
};

inline Vector2 operator*(float scalar, const Vector2& v) {
    return {v.x * scalar, v.y * scalar};
}

/**
 * @struct ColorRGBA
 * @brief Represents an 8-bit RGBA color.
 */
struct ColorRGBA {
    uint8_t r = 255;
    uint8_t green = 255;
    uint8_t b = 255;
    uint8_t a = 255;

    ColorRGBA() = default;
    ColorRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
        : r(r), green(g), b(b), a(a) {}

    static ColorRGBA Red()     { return {240, 80, 80}; }
    static ColorRGBA Green()   { return {80, 200, 120}; }
    static ColorRGBA Blue()    { return {80, 160, 240}; }
    static ColorRGBA Yellow()  { return {250, 220, 80}; }
    static ColorRGBA Purple()  { return {170, 100, 230}; }
    static ColorRGBA Orange()  { return {245, 140, 60}; }
    static ColorRGBA Cyan()    { return {60, 210, 230}; }
    static ColorRGBA Magenta() { return {230, 80, 190}; }
    static ColorRGBA White()   { return {255, 255, 255}; }
    static ColorRGBA Black()   { return {0, 0, 0}; }
    static ColorRGBA Gray()    { return {128, 128, 128}; }
};

} // namespace Elysium
