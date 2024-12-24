#pragma once

namespace Phantom
{
    class Vector4f
    {
    public:
        Vector4f(float x = 0.0f, float y = 0.0f, float z = 0.0f, float a = 0.0f);

        float Dot(const Vector4f& other) const;
        Vector4f Cross(const Vector4f& other) const;

        Vector4f operator+ (const Vector4f& rhs) const;
        Vector4f operator- (const Vector4f& rhs) const;
        Vector4f& operator+= (const Vector4f& rhs);
        Vector4f& operator-= (const Vector4f& rhs);
        Vector4f operator* (float rhs) const;
        Vector4f& operator*= (float rhs);
        Vector4f& operator= (const Vector4f& rhs);

    private:
        float m_v[4];
    };
}
