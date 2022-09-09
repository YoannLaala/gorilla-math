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
	const Vector2f Vector2f::ZERO     = Vector2f(0.0f,0.0f);
    const Vector2f Vector2f::UNIT_X   = Vector2f(1.0f,0.0f);
    const Vector2f Vector2f::UNIT_Y   = Vector2f(0.0f,1.0f);
    const Vector2f Vector2f::ONE      = Vector2f(1.0f,1.0f);

    const Vector2d Vector2d::ZERO     = Vector2d(0.0,0.0);
    const Vector2d Vector2d::UNIT_X   = Vector2d(1.0,0.0);
    const Vector2d Vector2d::UNIT_Y   = Vector2d(0.0,1.0);
    const Vector2d Vector2d::ONE      = Vector2d(1.0,1.0);

    const Vector2i Vector2i::ZERO     = Vector2i(0,0);
    const Vector2i Vector2i::UNIT_X   = Vector2i(1,0);
    const Vector2i Vector2i::UNIT_Y   = Vector2i(0,1);
    const Vector2i Vector2i::ONE      = Vector2i(1,1);

    const Vector2l Vector2l::ZERO     = Vector2l(0,0);
    const Vector2l Vector2l::UNIT_X   = Vector2l(1,0);
    const Vector2l Vector2l::UNIT_Y   = Vector2l(0,1);
    const Vector2l Vector2l::ONE      = Vector2l(1,1);

    const Vector2u Vector2u::ZERO     = Vector2u(0,0);
    const Vector2u Vector2u::UNIT_X   = Vector2u(1,0);
    const Vector2u Vector2u::UNIT_Y   = Vector2u(0,1);
    const Vector2u Vector2u::ONE      = Vector2u(1,1);

    const Vector2ul Vector2ul::ZERO   = Vector2ul(0,0);
    const Vector2ul Vector2ul::UNIT_X = Vector2ul(1,0);
    const Vector2ul Vector2ul::UNIT_Y = Vector2ul(0,1);
    const Vector2ul Vector2ul::ONE    = Vector2ul(1,1);

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
