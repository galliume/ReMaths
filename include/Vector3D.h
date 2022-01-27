#include <iostream>

namespace ReM 
{
    struct Vector3D
    {
        float x, y, z;

        Vector3D() = default;

        Vector3D(float a, float b, float c)
        {
            x = a;
            y = b;
            z = c;
        }

        float& operator[](int i)
        {
            return ((&x)[i]);
        }

        const float& operator [](int i) const
        {
            
            return ((&x)[i]);
        }
    };
}