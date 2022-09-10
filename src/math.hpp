#pragma once

/******************************************************************************
**  Includes
******************************************************************************/
#include "vector2.hpp"
#include "vector3.hpp"
// #include "vector4.hpp"
// #include "quaternion.hpp"
// #include "matrix33.hpp"
// #include "matrix44.hpp"
#include <cstdint>

/******************************************************************************
**  Class Declaration
******************************************************************************/
namespace Gorilla { namespace Math
{
    constexpr float	K_PI            = 3.141592654f;
    constexpr float	K_2PI           = 6.283185307f;
    constexpr float	K_1DIVPI        = 0.318309886f;
    constexpr float	K_1DIV2PI       = 0.159154943f;
    constexpr float	K_PIDIV2        = 1.570796327f;
    constexpr float	K_PIDIV4        = 0.785398163f;

    using Vector2f =    Vector2<float>;
    using Vector2d =    Vector2<double>;
    using Vector2i =    Vector2<int32_t>;
    using Vector2l =    Vector2<int64_t>;
    using Vector2u =    Vector2<uint32_t>;
    using Vector2ul =   Vector2<uint64_t>;

    template <typename T>
    inline int32_t sign(T& value)
    {
        return (T(0) < value) - (value < T(0));
    }

    template <typename T>
    inline T min(const T& a,const T& b)
    {
        return(a < b ? a : b);
    }

    template <typename T>
    inline T max(const T& a,const T& b)
    {
        return(a > b ? a : b);
    }

    template<typename T>
    inline T clamp(const T& value, const T& min_value, const T& max_value)
    {
        return min<T>(max_value, max<T>(min_value, value));
    }

    template <typename T>
    inline T abs(const T& a)
    {
        return(a < 0 ? -a : a);
    }

    inline float to_radian(float degree)
    {
        return degree * (K_PI / 180.0f);
    }

    inline float to_degree(float radian)
    {
        return radian * (180.0f / K_PI);
    }

    float cos(float value);
    float sin(float value);
    float sqrt(float value);
    float log2(float value);
}}
