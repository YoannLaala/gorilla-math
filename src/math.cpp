/******************************************************************************
**  Includes
******************************************************************************/
#include "math.hpp"
#include <math.h>

/******************************************************************************
**  Class Definition
******************************************************************************/
namespace Gorilla { namespace Math
{
    template<> const Vector2f Vector2f::ZERO     = Vector2f(0.0f,0.0f);
    template<> const Vector2f Vector2f::UNIT_X   = Vector2f(1.0f,0.0f);
    template<> const Vector2f Vector2f::UNIT_Y   = Vector2f(0.0f,1.0f);
    template<> const Vector2f Vector2f::ONE      = Vector2f(1.0f,1.0f);

    template<> const Vector2d Vector2d::ZERO     = Vector2d(0.0,0.0);
    template<> const Vector2d Vector2d::UNIT_X   = Vector2d(1.0,0.0);
    template<> const Vector2d Vector2d::UNIT_Y   = Vector2d(0.0,1.0);
    template<> const Vector2d Vector2d::ONE      = Vector2d(1.0,1.0);

    template<> const Vector2i Vector2i::ZERO     = Vector2i(0,0);
    template<> const Vector2i Vector2i::UNIT_X   = Vector2i(1,0);
    template<> const Vector2i Vector2i::UNIT_Y   = Vector2i(0,1);
    template<> const Vector2i Vector2i::ONE      = Vector2i(1,1);

    template<> const Vector2l Vector2l::ZERO     = Vector2l(0,0);
    template<> const Vector2l Vector2l::UNIT_X   = Vector2l(1,0);
    template<> const Vector2l Vector2l::UNIT_Y   = Vector2l(0,1);
    template<> const Vector2l Vector2l::ONE      = Vector2l(1,1);

    template<> const Vector2u Vector2u::ZERO     = Vector2u(0,0);
    template<> const Vector2u Vector2u::UNIT_X   = Vector2u(1,0);
    template<> const Vector2u Vector2u::UNIT_Y   = Vector2u(0,1);
    template<> const Vector2u Vector2u::ONE      = Vector2u(1,1);

    template<> const Vector2ul Vector2ul::ZERO   = Vector2ul(0,0);
    template<> const Vector2ul Vector2ul::UNIT_X = Vector2ul(1,0);
    template<> const Vector2ul Vector2ul::UNIT_Y = Vector2ul(0,1);
    template<> const Vector2ul Vector2ul::ONE    = Vector2ul(1,1);

    template<> const Vector3f Vector3f::ZERO     = Vector3f(0.0f,0.0f);
    template<> const Vector3f Vector3f::UNIT_X   = Vector3f(1.0f,0.0f);
    template<> const Vector3f Vector3f::UNIT_Y   = Vector3f(0.0f,1.0f);
    template<> const Vector3f Vector3f::ONE      = Vector3f(1.0f,1.0f);

    template<> const Vector3d Vector3d::ZERO     = Vector3d(0.0,0.0);
    template<> const Vector3d Vector3d::UNIT_X   = Vector3d(1.0,0.0);
    template<> const Vector3d Vector3d::UNIT_Y   = Vector3d(0.0,1.0);
    template<> const Vector3d Vector3d::ONE      = Vector3d(1.0,1.0);

    template<> const Vector3i Vector3i::ZERO     = Vector3i(0,0);
    template<> const Vector3i Vector3i::UNIT_X   = Vector3i(1,0);
    template<> const Vector3i Vector3i::UNIT_Y   = Vector3i(0,1);
    template<> const Vector3i Vector3i::ONE      = Vector3i(1,1);

    template<> const Vector3l Vector3l::ZERO     = Vector3l(0,0);
    template<> const Vector3l Vector3l::UNIT_X   = Vector3l(1,0);
    template<> const Vector3l Vector3l::UNIT_Y   = Vector3l(0,1);
    template<> const Vector3l Vector3l::ONE      = Vector3l(1,1);

    template<> const Vector3u Vector3u::ZERO     = Vector3u(0,0);
    template<> const Vector3u Vector3u::UNIT_X   = Vector3u(1,0);
    template<> const Vector3u Vector3u::UNIT_Y   = Vector3u(0,1);
    template<> const Vector3u Vector3u::ONE      = Vector3u(1,1);

    template<> const Vector3ul Vector3ul::ZERO   = Vector3ul(0,0);
    template<> const Vector3ul Vector3ul::UNIT_X = Vector3ul(1,0);
    template<> const Vector3ul Vector3ul::UNIT_Y = Vector3ul(0,1);
    template<> const Vector3ul Vector3ul::ONE    = Vector3ul(1,1);

    float cos(float value)
    {
        return cosf(value);
    }

    float sin(float value)
    {
        return sinf(value);
    }

    float sqrt(float value)
    {
        return sqrtf(value);
    }

    float log2(float value)
    {
        return log2f(value);
    }
}}
