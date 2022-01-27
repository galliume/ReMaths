#include "gtest/gtest.h"
#include "Vector3D.h"

TEST(Vector3D, Init) {

    ReM::Vector3D vec3D = ReM::Vector3D(1, 2, 3);

    EXPECT_EQ(vec3D[0], 1);
    EXPECT_EQ(vec3D[1], 2);
    EXPECT_EQ(vec3D[2], 3);
}