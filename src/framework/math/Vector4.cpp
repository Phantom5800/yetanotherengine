#include "framework/math/Vector4.h"
#include <cstring>

namespace Phantom
{
    Vector4f::Vector4f(float x, float y, float z, float a) :
        m_v{x,y,z,a}
    {

    }

    float Vector4f::Dot(const Vector4f& other) const
    {
        return m_v[0] * other.m_v[0] + m_v[1] * other.m_v[1] + m_v[2] * other.m_v[2] + m_v[3] * other.m_v[3];
    }

    Vector4f Vector4f::Cross(const Vector4f& other) const
    {
        return Vector4f(
            m_v[1] * other.m_v[2] - m_v[2] * other.m_v[1],
            m_v[2] * other.m_v[0] - m_v[0] * other.m_v[2],
            m_v[0] * other.m_v[1] - m_v[1] * other.m_v[0],
            1.0f
        );
    }

    Vector4f Vector4f::operator+ (const Vector4f& rhs) const
    {
        return Vector4f(
            m_v[0] + rhs.m_v[0],
            m_v[1] + rhs.m_v[1],
            m_v[2] + rhs.m_v[2],
            m_v[3] + rhs.m_v[3]
        );
    }

    Vector4f Vector4f::operator- (const Vector4f& rhs) const
    {
        return Vector4f(
            m_v[0] - rhs.m_v[0],
            m_v[1] - rhs.m_v[1],
            m_v[2] - rhs.m_v[2],
            m_v[3] - rhs.m_v[3]
        );
    }

    Vector4f& Vector4f::operator+= (const Vector4f& rhs)
    {
        m_v[0] += rhs.m_v[0];
        m_v[1] += rhs.m_v[1];
        m_v[2] += rhs.m_v[2];
        m_v[3] += rhs.m_v[3];
        return *this;
    }

    Vector4f& Vector4f::operator-= (const Vector4f& rhs)
    {
        m_v[0] -= rhs.m_v[0];
        m_v[1] -= rhs.m_v[1];
        m_v[2] -= rhs.m_v[2];
        m_v[3] -= rhs.m_v[3];
        return *this;
    }

    Vector4f Vector4f::operator* (float rhs) const
    {
        return Vector4f(
            m_v[0] * rhs,
            m_v[1] * rhs,
            m_v[2] * rhs,
            m_v[3] * rhs
        );
    }

    Vector4f& Vector4f::operator*= (float rhs)
    {
        m_v[0] *= rhs;
        m_v[1] *= rhs;
        m_v[2] *= rhs;
        m_v[3] *= rhs;
        return *this;
    }

    Vector4f& Vector4f::operator= (const Vector4f& rhs)
    {
        std::memcpy(m_v, rhs.m_v, sizeof(m_v));
        return *this;
    }
}
