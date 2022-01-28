#include "gtest/gtest.h"
#include "Vector3D.h"

TEST(Vector3D, Init) {

    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);

    EXPECT_EQ(vec3D[0], 1);
    EXPECT_EQ(vec3D[1], 2);
    EXPECT_EQ(vec3D[2], 3);
}

TEST(Vector3D, Multiply) {

    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);
    vec3D *= 2;

    EXPECT_EQ(vec3D[0], 2);
    EXPECT_EQ(vec3D[1], 4);
    EXPECT_EQ(vec3D[2], 6);

    ReM::Vector3D vec3D2 = vec3D * 2;

    EXPECT_EQ(vec3D2[0], 4);
    EXPECT_EQ(vec3D2[1], 8);
    EXPECT_EQ(vec3D2[2], 12);
}

TEST(Vector3D, Divide) {

    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);
    vec3D /= 2;

    EXPECT_EQ(vec3D[0], 0.5);
    EXPECT_EQ(vec3D[1], 1);
    EXPECT_EQ(vec3D[2], 1.5);

    ReM::Vector3D vec3D2 = vec3D / 2;

    EXPECT_EQ(vec3D2[0], 0.25);
    EXPECT_EQ(vec3D2[1], 0.5);
    EXPECT_EQ(vec3D2[2], 0.75);
}

TEST(Vector3D, Minus) {
    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);

    ReM::Vector3D vec3D2 = vec3D - 2;

    EXPECT_EQ(vec3D2[0], -1);
    EXPECT_EQ(vec3D2[1], 0);
    EXPECT_EQ(vec3D2[2], 1);

    vec3D2 -= vec3D;

    EXPECT_EQ(vec3D2[0], -2);
    EXPECT_EQ(vec3D2[1], -2);
    EXPECT_EQ(vec3D2[2], -2);

    ReM::Vector3D vec3D3 = vec3D - vec3D2;

    EXPECT_EQ(vec3D3[0], 3);
    EXPECT_EQ(vec3D3[1], 4);
    EXPECT_EQ(vec3D3[2], 5);
}

TEST(Vector3D, Add) {
    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);

    ReM::Vector3D vec3D2 = vec3D + 2;

    EXPECT_EQ(vec3D2[0], 3);
    EXPECT_EQ(vec3D2[1], 4);
    EXPECT_EQ(vec3D2[2], 5);

    vec3D2 += vec3D;

    EXPECT_EQ(vec3D2[0], 4);
    EXPECT_EQ(vec3D2[1], 6);
    EXPECT_EQ(vec3D2[2], 8);


    ReM::Vector3D vec3D4 = vec3D + vec3D2;

    EXPECT_EQ(vec3D4[0], 5);
    EXPECT_EQ(vec3D4[1], 8);
    EXPECT_EQ(vec3D4[2], 11);
}

TEST(Vector3D, Magnitude) {
    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);
    EXPECT_FLOAT_EQ(ReM::Magnitude(vec3D), 3.7416575);
}

TEST(Vector3D, Normalize) {
    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);
    ReM::Vector3D vec3DNormalized = ReM::Normalize(vec3D);

    EXPECT_FLOAT_EQ(vec3DNormalized[0], 0.26726124);
    EXPECT_FLOAT_EQ(vec3DNormalized[1], 0.53452247);
    EXPECT_FLOAT_EQ(vec3DNormalized[2], 0.80178368);
}

TEST(Vector3D, Dot) {
    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);
    ReM::Vector3D vec3D2 = ReM::Vector3D(4, 5, 6);

    EXPECT_FLOAT_EQ(sqrt(ReM::Dot(vec3D, vec3D)), ReM::Magnitude(vec3D));
    EXPECT_FLOAT_EQ(ReM::Dot(vec3D, vec3D2), 32);
}

TEST(Vector3D, Cross) {
    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);
    ReM::Vector3D vec3D2 = ReM::Vector3D(4, 5, 6);
    ReM::Vector3D vec3D3 = ReM::Cross(vec3D, vec3D2);

    EXPECT_FLOAT_EQ(vec3D3[0], -3);
    EXPECT_FLOAT_EQ(vec3D3[1], 6);
    EXPECT_FLOAT_EQ(vec3D3[2], -3);
}