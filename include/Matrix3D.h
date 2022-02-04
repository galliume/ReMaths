#include <iostream>
#include <cmath>

#include "Vector3D.h"

namespace ReM 
{
    struct Matrix3D
    {
        public:
            Matrix3D() = default;

            Matrix3D(
                float n00, float n01, float n02,
                float n10, float n11, float n12,
                float n20, float n21, float n22
            ) {
                n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
                n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
                n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
            }

            Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
            {
                n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
                n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
                n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
            }

            float& operator()(int i, int j)
            {
                return n[j][i];
            }

            const float& operator()(int i, int j) const
            {
                return n[j][i];
            }

            Vector3D& operator[](int j)
            {
                return (*reinterpret_cast<Vector3D*>(n[j]));
            }

            const Vector3D& operator[](int j) const
            {
                return (*reinterpret_cast<const Vector3D*>(n[j]));
            }
        private:
            float n[3][3];
    };

    Matrix3D operator *(const Matrix3D& a, const Matrix3D& b)
    {
        return Matrix3D(
            a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) + a(0, 2) * b(2, 0),
            a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) + a(0, 2) * b(2, 1),
            a(0, 0) * b(0, 2) + a(0, 1) * b(1, 2) + a(0, 2) * b(2, 2),

            a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) + a(1, 2) * b(2, 0),
            a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) + a(1, 2) * b(2, 1),
            a(1, 0) * b(0, 2) + a(1, 1) * b(1, 2) + a(1, 2) * b(2, 2),

            a(2, 0) * b(0, 0) + a(2, 1) * b(1, 0) + a(2, 2) * b(2, 0),
            a(2, 0) * b(0, 1) + a(2, 1) * b(1, 1) + a(2, 2) * b(2, 1),
            a(2, 0) * b(0, 2) + a(2, 1) * b(1, 2) + a(2, 2) * b(2, 2)
            );
    }

    Vector3D operator *(const Matrix3D& m, const Vector3D& v)
    {
        return Vector3D(
            m(0, 0) * v.x + m(0, 1) * v.y + m(0, 2) * v.z,
            m(1, 0) * v.x + m(1, 1) * v.y + m(1, 2) * v.z,
            m(2, 0) * v.x + m(2, 1) * v.y + m(2, 2) * v.z
        );
    }

    inline float Determinant(const Matrix3D& m) 
    {
        return m(0, 0) * (m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1))
            + m(0, 1) * (m(1, 2) * m(2, 0) - m(1, 0) * m(2, 2))
            + m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0));
    }

    Matrix3D Inverse(const Matrix3D& m)
    {
        const Vector3D& a = m[0];
        const Vector3D& b = m[1];
        const Vector3D& c = m[2];

        Vector3D r0 = Cross(b, c);
        Vector3D r1 = Cross(c, a);
        Vector3D r2 = Cross(a, b);

        float invDet = 1.0F / Dot(r2, c);

        return Matrix3D(
            r0.x * invDet, r0.y* invDet, r0.z * invDet,
            r1.x * invDet, r1.y* invDet, r1.z * invDet,
            r2.x * invDet, r2.y* invDet, r2.z * invDet
        );
    }
    
    Matrix3D MakeRotationX(float t) 
    {
        float c = cos(t);
        float s = sin(t);

        return Matrix3D(
            1.0f, 0.0f, 0.0f, 
            0.0f, c, -s,
            0.0f, s, c
        );
    }

    Matrix3D MakeRotationY(float t) 
    {
        float c = cos(t);
        float s = sin(t);

        return Matrix3D(
            c, 0.0f, s, 
            0.0f, 1.0f, 0.0f,
            -s, 0.0f, c
        );
    }

    Matrix3D MakeRotationZ(float t) 
    {
        float c = cos(t);
        float s = sin(t);

        return Matrix3D(
            c, -s, 0.0f,
            s, c, 0.0f,
            0.0f, 0.0f, 1.0f
        );
    }
}