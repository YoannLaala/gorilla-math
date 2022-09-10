#pragma once

#include <cstdint>
#include <math.h>

/******************************************************************************
**  Class Declaration
******************************************************************************/
namespace Gorilla { namespace Math
{
    template <typename T>
    class Vector3
    {
    public:
        static const Vector3 ZERO;
        static const Vector3 UNIT_X;
        static const Vector3 UNIT_Y;
        static const Vector3 ONE;

        Vector3();
        Vector3(T x, T y, T z);
        Vector3(const Vector3& reference);

        inline void         set             (T x, T y, T z);
        inline void         set_x           (T x);
        inline void         set_y           (T y);
        inline void         set_z           (T z);

        inline void         add             (T x, T y, T z);
        inline void         add_x           (T x);
        inline void         add_y           (T y);
        inline void         add_z           (T z);

        inline void         sub             (T x, T y, T z);
        inline void         sub_x           (T x);
        inline void         sub_y           (T y);
        inline void         sub_z           (T z);

        inline void         mul             (T x, T y, T z);
        inline void         mul_x           (T x);
        inline void         mul_y           (T y);
        inline void         mul_z           (T z);

        inline void         div             (T x, T y, T z);
        inline void         div_x           (T x);
        inline void         div_y           (T y);
        inline void         div_z           (T z);

        inline Vector3      cross           (const Vector3& reference) const;
        inline T            dot             (const Vector3& reference) const;
        inline T            length_square   () const;
        T                   length          () const;
        inline void         normalize       ();

        inline bool         operator==      (const Vector3& reference) const;
        inline bool         operator!=      (const Vector3& reference) const;

        inline Vector3      operator+       (const Vector3& reference) const;
        inline Vector3      operator+       (T value) const;
        inline Vector3&     operator+=      (const Vector3& reference);
        inline Vector3&     operator+=      (T value);

        inline Vector3      operator-       (const Vector3& reference) const;
        inline Vector3      operator-       (T value) const;
        inline Vector3&     operator-=      (const Vector3& reference);
        inline Vector3&     operator-=      (T value);

        inline Vector3      operator*       (const Vector3& reference) const;
        inline Vector3      operator*       (T value) const;
        inline Vector3&     operator*=      (const Vector3& reference);
        inline Vector3&     operator*=      (T value);

        inline Vector3      operator/       (const Vector3& reference) const;
        inline Vector3      operator/       (T value) const;
        inline Vector3&     operator/=      (const Vector3& reference);
        inline Vector3&     operator/=      (T value);

        inline T            operator[]      (uint32_t index) const;
        inline T&           operator[]      (uint32_t index);

        inline T            get_x           () const;
        inline T            get_y           () const;
        inline T            get_z           () const;

    private:
        T m_data[3];
    };

    //! @brief      constructor
    template <typename T>
    Vector3<T>::Vector3()
    {
        m_data[0] = (T)0;
        m_data[1] = (T)0;
        m_data[2] = (T)0;
    }

    //! @brief      constructor
    template <typename T>
    Vector3<T>::Vector3(T x, T y, T z)
    {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
    }

    //!	@brief      constructor
    template <typename T>
    Vector3<T>::Vector3(const Vector3& reference)
    {
        m_data[0] = reference.get_x();
        m_data[1] = reference.get_y();
        m_data[3] = reference.get_z();
    }

    //! @brief      set
    template <typename T>
    void Vector3<T>::set(T x, T y, T z)
    {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
    }

    //! @brief      set_x
    template <typename T>
    void Vector3<T>::set_x(T x)
    {
        m_data[0] = x;
    }

    //! @brief      set_y
    template <typename T>
    void Vector3<T>::set_y(T y)
    {
        m_data[1] = y;
    }

    //! @brief      set_z
    template <typename T>
    void Vector3<T>::set_z(T z)
    {
        m_data[2] = z;
    }

    //! @brief      add
    template <typename T>
    void Vector3<T>::add(T x, T y, T z)
    {
        m_data[0] += x;
        m_data[1] += y;
        m_data[2] += z;
    }

    //! @brief      add_x
    template <typename T>
    void Vector3<T>::add_x(T x)
    {
        m_data[0] += x;
    }

    //! @brief      add_y
    template <typename T>
    void Vector3<T>::add_y(T y)
    {
        m_data[1] += y;
    }

    //! @brief      add_z
    template <typename T>
    void Vector3<T>::add_z(T z)
    {
        m_data[2] += z;
    }

    //! @brief      sub
    template <typename T>
    void Vector3<T>::sub(T x, T y, T z)
    {
        m_data[0] -= x;
        m_data[1] -= y;
        m_data[2] -= z;
    }

    //! @brief      sub_x
    template <typename T>
    void Vector3<T>::sub_x(T x)
    {
        m_data[0] -= x;
    }

    //! @brief      sub_y
    template <typename T>
    void Vector3<T>::sub_y(T y)
    {
        m_data[1] -= y;
    }

    //! @brief      sub_z
    template <typename T>
    void Vector3<T>::sub_z(T z)
    {
        m_data[2] -= z;
    }

    //! @brief      mul
    template <typename T>
    void Vector3<T>::mul(T x, T y, T z)
    {
        m_data[0] *= x;
        m_data[1] *= y;
        m_data[2] *= z;
    }

    //! @brief      mul_x
    template <typename T>
    void Vector3<T>::mul_x(T x)
    {
        m_data[0] *= x;
    }

    //! @brief      mul_y
    template <typename T>
    void Vector3<T>::mul_y(T y)
    {
        m_data[1] *= y;
    }

    //! @brief      mul_z
    template <typename T>
    void Vector3<T>::mul_z(T z)
    {
        m_data[2] *= z;
    }

    //! @brief      div
    template <typename T>
    void Vector3<T>::div(T x, T y, T z)
    {
        m_data[0] /= x;
        m_data[1] /= y;
        m_data[2] /= z;
    }

    //! @brief      div_x
    template <typename T>
    void Vector3<T>::div_x(T x)
    {
        m_data[0] /= x;
    }

    //! @brief      div_y
    template <typename T>
    void Vector3<T>::div_y(T y)
    {
        m_data[1] /= y;
    }

    //! @brief      div_z
    template <typename T>
    void Vector3<T>::div_z(T z)
    {
        m_data[2] /= z;
    }

    //! @brief      cross
    template <typename T>
    Vector3<T> Vector3<T>::cross(const Vector3& reference) const
    {
        return Vector3<T>((m_data[1] * reference.get_z()) - (m_data[2] * reference.get_y()), (m_data[2] * reference.get_x()) - (m_data[0] * reference.get_z()), (m_data[0] * reference.get_y()) - (m_data[1] * reference.get_x()));
    }

    //! @brief      dot
    template <typename T>
    T Vector3<T>::dot(const Vector3& reference) const
    {
        return (m_data[0] * reference.get_x()) + (m_data[1] * reference.get_y()) + (m_data[2] * reference.get_z());
    }

    //! @brief      length_square
    template <typename T>
    T Vector3<T>::length_square() const
    {
        return (m_data[0] * m_data[0]) + (m_data[1] * m_data[1]) + (m_data[2] * m_data[2]);
    }

    //! @brief      length
    template <typename T>
    T Vector3<T>::length() const
    {
        return (T)sqrt((float)length_square());
    }

    //! @brief      normalize
    template <typename T>
    void Vector3<T>::normalize()
    {
        T length_inverse = 1.0f / length();
        mul(length_inverse, length_inverse, length_inverse);
    }

    //! @brief      operator==
    template <typename T>
    bool Vector3<T>::operator==(const Vector3& reference) const
    {
        return m_data[0] == reference.get_x() && m_data[1] == reference.get_y() && m_data[2] == reference.get_z();
    }

    //! @brief      operator!=
    template <typename T>
    bool Vector3<T>::operator!=(const Vector3& reference) const
    {
        return m_data[0] != reference.get_x() || m_data[1] != reference.get_y() || m_data[2] != reference.get_z();
    }

    //! @brief      operator+
    template <typename T>
    Vector3<T> Vector3<T>::operator+(const Vector3& reference) const
    {
        return Vector3(m_data[0] + reference.get_x(), m_data[1] + reference.get_y(), m_data[2] + reference.get_z());
    }

    //! @brief      operator+
    template <typename T>
    Vector3<T> Vector3<T>::operator+(T value) const
    {
        return Vector3(m_data[0] + value, m_data[1] + value, m_data[2] + value);
    }

    //! @brief      operator+=
    template <typename T>
    Vector3<T>& Vector3<T>::operator+=(const Vector3& reference)
    {
        add(reference.get_x(), reference.get_y());
        return *this;
    }

    //! @brief      operator+=
    template <typename T>
    Vector3<T>&Vector3<T>::operator+=(T value)
    {
        add(value, value);
        return *this;
    }

    //! @brief      operator-
    template <typename T>
    Vector3<T> Vector3<T>::operator-(const Vector3& reference) const
    {
        return Vector3(m_data[0] - reference.get_x(), m_data[1] - reference.get_y());
    }

    //! @brief      operator-
    template <typename T>
    Vector3<T> Vector3<T>::operator-(T value) const
    {
        return Vector3(m_data[0] - value, m_data[1] - value, m_data[2] - value);
    }

    //! @brief      operator-=
    template <typename T>
    Vector3<T>& Vector3<T>::operator-=(const Vector3& reference)
    {
        sub(reference.get_x(), reference.get_y());
        return *this;
    }

    //! @brief      operator-=
    template <typename T>
    Vector3<T>& Vector3<T>::operator-=(T value)
    {
        sub(value, value);
        return *this;
    }

    //! @brief      operator*
    template <typename T>
    Vector3<T> Vector3<T>::operator*(const Vector3& reference) const
    {
        return Vector3(m_data[0] * reference.get_x(), m_data[1] * reference.get_y());
    }

    //! @brief      operator*
    template <typename T>
    Vector3<T> Vector3<T>::operator*(T value) const
    {
        return Vector3(m_data[0] * value, m_data[1] * value);
    }

    //! @brief      operator*=
    template <typename T>
    Vector3<T>& Vector3<T>::operator*=(const Vector3& reference)
    {
        mul(reference.get_x(), reference.get_y());  return *this;
    }

    //! @brief      operator*=
    template <typename T>
    Vector3<T>& Vector3<T>::operator*=(T value)
    {
        mul(value, value);  return *this;
    }

    //! @brief      operator/
    template <typename T>
    Vector3<T> Vector3<T>::operator/(const Vector3& reference) const
    {
        return Vector3(m_data[0] / reference.get_x(), m_data[1] / reference.get_y());
    }

    //! @brief      operator/
    template <typename T>
    Vector3<T> Vector3<T>::operator/(T value) const
    {
        T fInverse = 1.0f / value;
        return Vector3(m_data[0] * fInverse, m_data[1] * fInverse);
    }

    //! @brief      operator/=
    template <typename T>
    Vector3<T>& Vector3<T>::operator/=(const Vector3& reference)
    {
        Div(reference.get_x(), reference.get_y());  return *this;
    }

    //! @brief      operator/=
    template <typename T>
    Vector3<T>& Vector3<T>:: operator/=(T value)
    {
        T fInverse = 1.0f / value; Mul(fInverse, fInverse);
        return *this;
    }

    //! @brief      operator[]
    template <typename T>
    T Vector3<T>::operator[](uint32_t index) const
    {
        return m_data[index];
    }

    //! @brief      operator[]
    template <typename T>
    T& Vector3<T>::operator[](uint32_t index)
    {
        return m_data[index];
    }

    //! @brief      get_x
    template <typename T>
    T Vector3<T>::get_x() const
    {
        return m_data[0];
    }

    //! @brief      get_y
    template <typename T>
    T Vector3<T>::get_y() const
    {
        return m_data[1];
    }

    //! @brief      get_z
    template <typename T>
    T Vector3<T>::get_z() const
    {
        return m_data[2];
    }
}}
