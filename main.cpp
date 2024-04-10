#include "gtest/gtest.h"
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

// 最大子数组和
int MSAS(vector<int>& arr) {
    int n = arr.size();
    int MS = 0;
    int CS = 0;

    for (int i = 0; i < n; ++i) {
        CS = max(0, CS + arr[i]);
        MS = max(MS, CS);
    }

    return MS;
}

// 处理所有负数的测试用例。
TEST(MaxSubArraySumTest, HandlesAllNegativeNumbers) {

    std::vector<int> N = { -9, -8, -7, -6 };
    EXPECT_EQ(MSAS(N), 0);
}

// 处理所有正数的测试用例。
TEST(MaxSubArraySumTest, HandlesAllPositiveNumbers) {

    std::vector<int> N = { 1, 2, 3 };
    EXPECT_EQ(MSAS(N), 6);
}


//Google Test主程序
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
