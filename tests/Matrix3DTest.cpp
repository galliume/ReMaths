#include "gtest/gtest.h"
#include "Matrix3D.h"

TEST(Matrix3D, Init) {

    ReM::Matrix3D matrix3D = ReM::Matrix3D(
        1.0, 2.0, 3.0, 
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0
    );

    ReM::Vector3D vec3D =  matrix3D[0];
    ReM::Vector3D vec3D2 = ReM::Vector3D(1.0, 2.0, 3.0);


    EXPECT_EQ(matrix3D(1, 0), 2.0);
    EXPECT_EQ(matrix3D(0, 2), 7.0);
    EXPECT_EQ(matrix3D(2, 1), 6.0);
    EXPECT_EQ(vec3D[0], vec3D2[0]);
    EXPECT_EQ(vec3D[1], vec3D2[1]);
    EXPECT_EQ(vec3D[2], vec3D2[2]);
}

