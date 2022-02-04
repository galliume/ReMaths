#include "gtest/gtest.h"
#include "Matrix3D.h"

TEST(Matrix3D, Init) {

    ReM::Matrix3D matrix3D = ReM::Matrix3D(
        1.0, 2.0, 3.0, 
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0
    );

    ReM::Matrix3D matrix3D2 = ReM::Matrix3D(
        1.2, 2.33, 3.2,
        4.4, 5.1, 6.0,
        7.56, 8.56, 9.1
    );

    ReM::Vector3D vec3D =  matrix3D[0];
    ReM::Vector3D vec3D2 = ReM::Vector3D(1.0, 2.0, 3.0);

    EXPECT_EQ(matrix3D(1, 0), 2.0);
    EXPECT_EQ(matrix3D(0, 2), 7.0);
    EXPECT_EQ(matrix3D(2, 1), 6.0);

    EXPECT_EQ(vec3D[0], vec3D2[0]);
    EXPECT_EQ(vec3D[1], vec3D2[1]);
    EXPECT_EQ(vec3D[2], vec3D2[2]);

    ReM::Matrix3D matrix3D3 = matrix3D * matrix3D2;

    EXPECT_FLOAT_EQ(matrix3D3(0, 0), 32.92);
    EXPECT_FLOAT_EQ(matrix3D3(1, 2), 97.8);
    EXPECT_FLOAT_EQ(matrix3D3(2, 1), 130.72);
    EXPECT_FLOAT_EQ(matrix3D3(1, 0), 66.8);

    ReM::Vector3D vec3D3 = matrix3D * vec3D2;

    EXPECT_FLOAT_EQ(vec3D3[0], 30);
    EXPECT_FLOAT_EQ(vec3D3[1], 36);
    EXPECT_FLOAT_EQ(vec3D3[2], 42);
}

TEST(Matrix3D, Determinant) {
    ReM::Matrix3D matrix3D = ReM::Matrix3D(
        1.0, 2.0, 3.0, 
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0
    );

    EXPECT_FLOAT_EQ(ReM::Determinant(matrix3D), 0.0);
}

TEST(Matrix3D, Inverse) {
    ReM::Matrix3D matrix3D = ReM::Matrix3D(
        1.0, 2.0, 1.0, 
        3.0, 5.0, 0.0, 
        4.0, 2.0, 6.0
    );

    ReM::Matrix3D matrix3D2 = ReM::Inverse(matrix3D);

    EXPECT_FLOAT_EQ(matrix3D2(1, 2), -0.15);
    EXPECT_FLOAT_EQ(matrix3D2(2, 1), -0.30);
    EXPECT_FLOAT_EQ(matrix3D2(1, 0), 0.90);
}

TEST(Matrix3D, RotationX) {
        ReM::Matrix3D matrix3D = ReM::Matrix3D(
        1.0, 2.0, 3.0, 
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0
    );

    //rotation of 0, should not move
    ReM::Matrix3D matrix3D2 = matrix3D * ReM::MakeRotationX(0.0f);

    EXPECT_FLOAT_EQ(matrix3D2(0, 0), 1.0);
    EXPECT_FLOAT_EQ(matrix3D2(1, 2), 6.0);
    EXPECT_FLOAT_EQ(matrix3D2(2, 1), 8.0);
    EXPECT_FLOAT_EQ(matrix3D2(1, 0), 4.0);

    matrix3D2 = matrix3D * ReM::MakeRotationX(90.0f);

    EXPECT_FLOAT_EQ(matrix3D2(0, 0), 1.0);
    EXPECT_FLOAT_EQ(matrix3D2(1, 2), -10.734411);
    EXPECT_FLOAT_EQ(matrix3D2(2, 1), 0.8853941);
    EXPECT_FLOAT_EQ(matrix3D2(1, 0), -8.050271);
}

TEST(Matrix3D, RotationY) {
        ReM::Matrix3D matrix3D = ReM::Matrix3D(
        1.0, 2.0, 3.0, 
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0
    );

    //rotation of 0, should not move
    ReM::Matrix3D matrix3D2 = matrix3D * ReM::MakeRotationY(0.0f);

    EXPECT_FLOAT_EQ(matrix3D2(0, 0), 1.0);
    EXPECT_FLOAT_EQ(matrix3D2(1, 2), 6.0);
    EXPECT_FLOAT_EQ(matrix3D2(2, 1), 8.0);
    EXPECT_FLOAT_EQ(matrix3D2(1, 0), 4.0);

    matrix3D2 = matrix3D * ReM::MakeRotationY(90.0f);

    EXPECT_FLOAT_EQ(matrix3D2(0, 0), 5.8099031);
    EXPECT_FLOAT_EQ(matrix3D2(1, 2), 6);
    EXPECT_FLOAT_EQ(matrix3D2(2, 1), -5.3725824);
    EXPECT_FLOAT_EQ(matrix3D2(1, 0), 4);
}

TEST(Matrix3D, RotationZ) {
    ReM::Matrix3D matrix3D = ReM::Matrix3D(
        1.0, 2.0, 3.0, 
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0
    );

    //rotation of 0, should not move
    ReM::Matrix3D matrix3D2 = matrix3D * ReM::MakeRotationZ(0.0f);

    EXPECT_FLOAT_EQ(matrix3D2(0, 0), 1.0);
    EXPECT_FLOAT_EQ(matrix3D2(1, 2), 6.0);
    EXPECT_FLOAT_EQ(matrix3D2(2, 1), 8.0);
    EXPECT_FLOAT_EQ(matrix3D2(1, 0), 4.0);

    matrix3D2 = matrix3D * ReM::MakeRotationZ(90.0f);

    EXPECT_FLOAT_EQ(matrix3D2(0, 0), -4.0240602);
    EXPECT_FLOAT_EQ(matrix3D2(1, 2), -0.0064518452);
    EXPECT_FLOAT_EQ(matrix3D2(2, 1), 8);
    EXPECT_FLOAT_EQ(matrix3D2(1, 0), -0.89829785);
}