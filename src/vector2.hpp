#pragma once

#include "math.hpp"
#include <cstdint>

/******************************************************************************
**  Class Declaration
******************************************************************************/
namespace Gorilla { namespace Math
{
    template <typename T>
    class Vector2
    {
    public:
        static const Vector2 ZERO;
        static const Vector2 UNIT_X;
        static const Vector2 UNIT_Y;
        static const Vector2 ONE;

        Vector2();
        Vector2(T x, T y);
        Vector2(const Vector2& reference);

        inline void         set             (T x, T y);
        inline void         set_x           (T x);
        inline void         set_y           (T y);

        inline void         add             (T x, T y);
        inline void         add_x           (T x);
        inline void         add_y           (T y);

        inline void         sub             (T x, T y);
        inline void         sub_x           (T x);
        inline void         sub_y           (T y);

        inline void         mul             (T x, T y);
        inline void         mul_x           (T x);
        inline void         mul_y           (T y);

        inline void         div             (T x, T y);
        inline void         div_x           (T x);
        inline void         div_y           (T y);

        inline T            cross           (const Vector2& reference) const;
        inline T            dot             (const Vector2& reference) const;
        inline T            length_square   () const;
        T                   length          () const;
        inline void         normalize       ();

        inline bool         operator==      (const Vector2& reference) const;
        inline bool         operator!=      (const Vector2& reference) const;

        inline Vector2      operator+       (const Vector2& reference) const;
        inline Vector2      operator+       (T value) const;
        inline Vector2&     operator+=      (const Vector2& reference);
        inline Vector2&     operator+=      (T value);

        inline Vector2      operator-       (const Vector2& reference) const;
        inline Vector2      operator-       (T value) const;
        inline Vector2&     operator-=      (const Vector2& reference);
        inline Vector2&     operator-=      (T value);

        inline Vector2      operator*       (const Vector2& reference) const;
        inline Vector2      operator*       (T value) const;
        inline Vector2&     operator*=      (const Vector2& reference);
        inline Vector2&     operator*=      (T value);

        inline Vector2      operator/       (const Vector2& reference) const;
        inline Vector2      operator/       (T value) const;
        inline Vector2&     operator/=      (const Vector2& reference);
        inline Vector2&     operator/=      (T value);

        inline T            operator[]      (uint32_t index) const;
        inline T&           operator[]      (uint32_t index);

        inline T            get_x           () const;
        inline T            get_y           () const;

    private:
        T m_data[2];
    };

    //! @brief      constructor
    template <typename T>
    Vector2<T>::Vector2()
    {
        memset(m_data, sizeof(m_data), 0);
    }

    //! @brief      constructor
    template <typename T>
    Vector2<T>::Vector2(T x, T y)
    {
        m_data[0] = x;
        m_data[1] = y;
    }

    //!	@brief      constructor
    template <typename T>
    Vector2<T>::Vector2(const Vector2& reference)
    {
        m_data[0] = reference.get_x();
        m_data[0] = reference.get_y();
    }

    //! @brief      set
    template <typename T>
    void Vector2<T>::set(T x, T y)
    {
        data[0] = x;
        data[1] = y;
    }

    //! @brief      set_x
    template <typename T>
    void Vector2<T>::set_x(T x)
    {
        data[0] = x;
    }

    //! @brief      set_y
    template <typename T>
    void Vector2<T>::set_y(T y)
    {
        data[1] = y;
    }

    //! @brief      add
    template <typename T>
    void Vector2<T>::add(T x, T y)
    {
        data[0] += x;
        data[1] += y;
    }

    //! @brief      add_x
    template <typename T>
    void Vector2<T>::add_x(T x)
    {
        data[0] += x;
    }

    //! @brief      add_y
    template <typename T>
    void Vector2<T>::add_y(T y)
    {
        data[1] += y;
    }

    //! @brief      sub
    template <typename T>
    void Vector2<T>::sub(T x, T y)
    {
        data[0] -= x;
        data[1] -= y;
    }

    //! @brief      sub_x
    template <typename T>
    void Vector2<T>::sub_x(T x)
    {
        data[0] -= x;
    }

    //! @brief      sub_y
    template <typename T>
    void Vector2<T>::sub_y(T y)
    {
        data[1] -= y;
    }

    //! @brief      mul
    template <typename T>
    void Vector2<T>::mul(T x, T y)
    {
        data[0] *= x;
        data[1] *= y;
    }

    //! @brief      mul_x
    template <typename T>
    void Vector2<T>::mul_x(T x)
    {
        data[0] *= x;
    }

    //! @brief      mul_y
    template <typename T>
    void Vector2<T>::mul_y(T y)
    {
        data[1] *= y;
    }

    //! @brief      div
    template <typename T>
    void Vector2<T>::div(T x, T y)
    {
        data[0] /= x;
        data[1] /= y;
    }

    //! @brief      div_x
    template <typename T>
    void Vector2<T>::div_x(T x)
    {
        data[0] /= x;
    }

    //! @brief      div_y
    template <typename T>
    void Vector2<T>::div_y(T y)
    {
        data[1] /= y;
    }

    //! @brief      cross
    template <typename T>
    T Vector2<T>::cross(const Vector2& reference) const
    {
        return (data[1] * reference.get_x()) - (data[0] * reference.get_y());
    }

    //! @brief      dot
    template <typename T>
    T Vector2<T>::dot(const Vector2& reference) const
    {
        return (data[0] * reference.get_x()) + (data[1] * reference.get_y());
    }

    //! @brief      length_square
    template <typename T>
    T Vector2<T>::length_square() const
    {
        return (data[0] * data[0]) + (data[1] * data[1]);
    }

    //! @brief      length
    template <typename T>
    T Vector2<T>::length() const
    {
        return (T)sqrt(length_square());
    }

    //! @brief      normalize
    template <typename T>
    void Vector2<T>::normalize()
    {
        T length_inverse = 1.0f / length();
        mul(length_inverse, length_inverse);

        return sqrt(length_square());
    }

    //! @brief      operator==
    template <typename T>
    bool Vector2<T>::operator==(const Vector2& reference) const
    {
        return data[0] == reference.get_x() && data[1] == reference.get_y();
    }

    //! @brief      operator!=
    template <typename T>
    bool Vector2<T>::operator!=(const Vector2& reference) const
    {
        return data[0] != reference.get_x() || data[1] != reference.get_y();
    }

    //! @brief      operator+
    template <typename T>
    Vector2<T> Vector2<T>::operator+(const Vector2& reference) const
    {
        return Vector2(data[0] + reference.get_x(), data[1] + reference.get_y());
    }

    //! @brief      operator+
    template <typename T>
    Vector2<T> Vector2<T>::operator+(T value) const
    {
        return Vector2(data[0] + value, data[1] + value);
    }

    //! @brief      operator+=
    template <typename T>
    Vector2<T>& Vector2<T>::operator+=(const Vector2& reference)
    {
        add(reference.get_x(), reference.get_y());
        return *this;
    }

    //! @brief      operator+=
    template <typename T>
    Vector2<T>&Vector2<T>::operator+=(T value)
    {
        add(value, value);
        return *this;
    }

    //! @brief      operator-
    template <typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2& reference) const
    {
        return Vector2(data[0] - reference.get_x(), data[1] - reference.get_y());
    }

    //! @brief      operator-
    template <typename T>
    Vector2<T> Vector2<T>::operator-(T value) const
    {
        return Vector2(data[0] - value, data[1] - value);
    }

    //! @brief      operator-=
    template <typename T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2& reference)
    {
        sub(reference.get_x(), reference.get_y());
        return *this;
    }

    //! @brief      operator-=
    template <typename T>
    Vector2<T>& Vector2<T>::operator-=(T value)
    {
        sub(value, value);
        return *this;
    }

    //! @brief      operator*
    template <typename T>
    Vector2<T> Vector2<T>::operator*(const Vector2& reference) const
    {
        return Vector2(data[0] * reference.get_x(), data[1] * reference.get_y());
    }

    //! @brief      operator*
    template <typename T>
    Vector2<T> Vector2<T>::operator*(T value) const
    {
        return Vector2(data[0] * value, data[1] * value);
    }

    //! @brief      operator*=
    template <typename T>
    Vector2<T>& Vector2<T>::operator*=(const Vector2& reference)
    {
        mul(reference.get_x(), reference.get_y());  return *this;
    }

    //! @brief      operator*=
    template <typename T>
    Vector2<T>& Vector2<T>::operator*=(T value)
    {
        mul(value, value);  return *this;
    }

    //! @brief      operator/
    template <typename T>
    Vector2<T> Vector2<T>::operator/(const Vector2& reference) const
    {
        return Vector2(data[0] / reference.get_x(), data[1] / reference.get_y());
    }

    //! @brief      operator/
    template <typename T>
    Vector2<T> Vector2<T>::operator/(T value) const
    {
        T fInverse = 1.0f / value;
        return Vector2(data[0] * fInverse, data[1] * fInverse);
    }

    //! @brief      operator/=
    template <typename T>
    Vector2<T>& Vector2<T>::operator/=(const Vector2& reference)
    {
        Div(reference.get_x(), reference.get_y());  return *this;
    }

    //! @brief      operator/=
    template <typename T>
    Vector2<T>& Vector2<T>:: operator/=(T value)
    {
        T fInverse = 1.0f / value; Mul(fInverse, fInverse);
        return *this;
    }

    //! @brief      operator[]
    template <typename T>
    T Vector2<T>::operator[](uint32_t index) const
    {
        return data[index];
    }

    //! @brief      operator[]
    template <typename T>
    T& Vector2<T>::operator[](uint32_t index)
    {
        return data[index];
    }

    //! @brief      get_x
    template <typename T>
    T Vector2<T>::get_x() const
    {
        return data[0];
    }

    //! @brief      get_y
    template <typename T>
    T Vector2<T>::get_y() const
    {
        return data[1];
    }
}}
