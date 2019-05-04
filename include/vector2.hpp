#pragma once

/******************************************************************************
**  Class Declaration
******************************************************************************/
namespace Gorilla { namespace Math
{
    template <typename TYPE = float>
    class Vector2
    {
    public:
        static const Vector2 ZERO;
        static const Vector2 UNIT_X;
        static const Vector2 UNIT_Y;
        static const Vector2 UNIT;
        
        Vector2();
        Vector2(TYPE x, TYPE y);
        Vector2(const Vector2& reference);
        
        inline void         set             (TYPE x, TYPE y);
        inline void         set_x           (TYPE x);
        inline void         set_y           (TYPE y);

        inline void         add             (TYPE x, TYPE y);
        inline void         add_x           (TYPE x);
        inline void         add_y           (TYPE y);

        inline void         sub             (TYPE x, TYPE y);
        inline void         subx            (TYPE x);
        inline void         suby            (TYPE y);

        inline void         mul             (TYPE x, TYPE y);
        inline void         mul_x           (TYPE x);
        inline void         mul_y           (TYPE y);

        inline void         div             (TYPE x, TYPE y);
        inline void         div_x           (TYPE x);
        inline void         div_y           (TYPE y);

        inline TYPE         cross           (const Vector2& reference) const;
        inline TYPE         dot             (const Vector2& reference) const;
        inline TYPE         length_square   () const;
        TYPE                length          () const;
        inline void         normalize       ();

        inline bool         operator==      (const Vector2& reference) const { return data[0] == reference.get_x() && data[1] == reference.get_y(); }
        inline bool         operator!=      (const Vector2& reference) const { return data[0] != reference.get_x() || data[1] != reference.get_y(); }

        inline Vector2      operator+       (const Vector2& reference) const { return Vector2(data[0] + reference.get_x(), data[1] + reference.get_y()); }
        inline Vector2      operator+       (TYPE value) const { return Vector2(data[0] + value, data[1] + value); }
        inline Vector2&     operator+=      (const Vector2& reference) { add(reference.get_x(), reference.get_y());  return *this; }
        inline Vector2&     operator+=      (TYPE value) { add(value, value);  return *this; }

        inline Vector2      operator-       (const Vector2& reference) const { return Vector2(data[0] - reference.get_x(), data[1] - reference.get_y()); }
        inline Vector2      operator-       (TYPE value) const { return Vector2(data[0] - value, data[1] - value); }
        inline Vector2&     operator-=      (const Vector2& reference) { sub(reference.get_x(), reference.get_y());  return *this; }
        inline Vector2&     operator-=      (TYPE value) { sub(value, value);  return *this; }

        inline Vector2      operator*       (const Vector2& reference) const { return Vector2(data[0] * reference.get_x(), data[1] * reference.get_y()); }
        inline Vector2      operator*       (TYPE value) const { return Vector2(data[0] * value, data[1] * value); }
        inline Vector2&     operator*=      (const Vector2& reference) { Mul(reference.get_x(), reference.get_y());  return *this; }
        inline Vector2&     operator*=      (TYPE value) { Mul(value, value);  return *this; }

        inline Vector2      operator/       (const Vector2& reference) const { return Vector2(data[0] / reference.get_x(), data[1] / reference.get_y()); }
        inline Vector2      operator/       (TYPE value) const { TYPE fInverse = 1.0f / value; return Vector2(data[0] * fInverse, data[1] * fInverse); }
        inline Vector2&     operator/=      (const Vector2& reference) { Div(reference.get_x(), reference.get_y());  return *this; }
        inline Vector2&     operator/=      (TYPE value) { TYPE fInverse = 1.0f / value; Mul(fInverse, fInverse);  return *this; }

        inline TYPE         operator[]      (unsigned int index) const;
        inline TYPE&        operator[]      (unsigned int index);

        inline TYPE         get_x           () const;
        inline TYPE         get_y           () const;

    private:
        TYPE data[2];
    };

    //! @brief      set
    template <typename TYPE>
    void Vector::set(TYPE x, TYPE y) 
    { 
        data[0] = x;
        data[1] = y; 
    }

    //! @brief      set_x
    template <typename TYPE>
    void Vector::set_x(TYPE x) 
    { 
        data[0] = x;
    }

    //! @brief      set_y
    template <typename TYPE>
    void Vector::set_x(TYPE y) 
    { 
        data[1] = y;
    }

    //! @brief      add
    template <typename TYPE>
    void Vector::add(TYPE x, TYPE y) 
    { 
        data[0] += x;
        data[1] += y; 
    }

    //! @brief      add_x
    template <typename TYPE>
    void Vector::add_x(TYPE x) 
    { 
        data[0] += x;
    }

    //! @brief      add_y
    template <typename TYPE>
    void Vector::add_x(TYPE y) 
    { 
        data[1] += y;
    }

    //! @brief      sub
    template <typename TYPE>
    void Vector::sub(TYPE x, TYPE y) 
    { 
        data[0] -= x;
        data[1] -= y; 
    }

    //! @brief      sub_x
    template <typename TYPE>
    void Vector::sub_x(TYPE x) 
    { 
        data[0] -= x;
    }

    //! @brief      sub_y
    template <typename TYPE>
    void Vector::sub_x(TYPE y) 
    { 
        data[1] -= y;
    }

    //! @brief      mul
    template <typename TYPE>
    void Vector::mul(TYPE x, TYPE y) 
    { 
        data[0] *= x;
        data[1] *= y; 
    }

    //! @brief      mul_x
    template <typename TYPE>
    void Vector::mul_x(TYPE x) 
    { 
        data[0] *= x;
    }

    //! @brief      mul_y
    template <typename TYPE>
    void Vector::mul_x(TYPE y) 
    { 
        data[1] *= y;
    }

    //! @brief      div
    template <typename TYPE>
    void Vector::div(TYPE x, TYPE y) 
    { 
        data[0] /= x;
        data[1] /= y; 
    }

    //! @brief      div_x
    template <typename TYPE>
    void Vector::div_x(TYPE x) 
    { 
        data[0] /= x;
    }

    //! @brief      div_y
    template <typename TYPE>
    void Vector::div_x(TYPE y) 
    { 
        data[1] /= y;
    }

    //! @brief      cross
    template <typename TYPE>
    TYPE Vector::cross(const Vector2& reference) const
    { 
        return (data[1] * reference.get_x()) - (data[0] * reference.get_y());
    }

    //! @brief      dot
    template <typename TYPE>
    TYPE Vector::dot(const Vector2& reference) const
    { 
        return (data[0] * reference.get_x()) + (data[1] * reference.get_y());
    }

    //! @brief      length_square
    template <typename TYPE>
    TYPE Vector::length_square() const
    { 
        return (data[0] * data[0]) + (data[1] * data[1]);
    }

    //! @brief      length
    template <typename TYPE>
    float Vector::length() const
    { 
        return sqrtf(length_square());
    }

    //! @brief      normalize
    template <typename TYPE>
    void Vector::normalize() const
    { 
        /*TYPE fLengthInverse = 1.0f / Length(); Mul(fLengthInverse, fLengthInverse);
        return sqrtf(length_square());*/
    }


        inline bool         operator==      (const Vector2& reference) const { return data[0] == reference.get_x() && data[1] == reference.get_y(); }
        inline bool         operator!=      (const Vector2& reference) const { return data[0] != reference.get_x() || data[1] != reference.get_y(); }

        inline Vector2      operator+       (const Vector2& reference) const { return Vector2(data[0] + reference.get_x(), data[1] + reference.get_y()); }
        inline Vector2      operator+       (TYPE value) const { return Vector2(data[0] + value, data[1] + value); }
        inline Vector2&     operator+=      (const Vector2& reference) { add(reference.get_x(), reference.get_y());  return *this; }
        inline Vector2&     operator+=      (TYPE value) { add(value, value);  return *this; }

        inline Vector2      operator-       (const Vector2& reference) const { return Vector2(data[0] - reference.get_x(), data[1] - reference.get_y()); }
        inline Vector2      operator-       (TYPE value) const { return Vector2(data[0] - value, data[1] - value); }
        inline Vector2&     operator-=      (const Vector2& reference) { sub(reference.get_x(), reference.get_y());  return *this; }
        inline Vector2&     operator-=      (TYPE value) { sub(value, value);  return *this; }

        inline Vector2      operator*       (const Vector2& reference) const { return Vector2(data[0] * reference.get_x(), data[1] * reference.get_y()); }
        inline Vector2      operator*       (TYPE value) const { return Vector2(data[0] * value, data[1] * value); }
        inline Vector2&     operator*=      (const Vector2& reference) { Mul(reference.get_x(), reference.get_y());  return *this; }
        inline Vector2&     operator*=      (TYPE value) { Mul(value, value);  return *this; }

        inline Vector2      operator/       (const Vector2& reference) const { return Vector2(data[0] / reference.get_x(), data[1] / reference.get_y()); }
        inline Vector2      operator/       (TYPE value) const { TYPE fInverse = 1.0f / value; return Vector2(data[0] * fInverse, data[1] * fInverse); }
        inline Vector2&     operator/=      (const Vector2& reference) { Div(reference.get_x(), reference.get_y());  return *this; }
        inline Vector2&     operator/=      (TYPE value) { TYPE fInverse = 1.0f / value; Mul(fInverse, fInverse);  return *this; }

    //! @brief      operator[]
    template <typename TYPE>
    TYPE Vector::operator[](unsigned int index) const
    { 
        return data[index];
    }

    //! @brief      operator[]
    template <typename TYPE>
    TYPE& Vector::operator[](unsigned int index)
    { 
        return data[index];
    }

    //! @brief      get_y
    template <typename TYPE>
    float Vector::get_x() const
    { 
        return data[1];
    }

    //! @brief      get_x
    template <typename TYPE>
    float Vector::get_x() const
    { 
        return data[0];
    }

    //! @brief      get_y
    template <typename TYPE>
    float Vector::get_x() const
    { 
        return data[1];
    }
}}
