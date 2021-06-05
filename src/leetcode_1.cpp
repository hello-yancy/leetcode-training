
#include "gtest/gtest.h"
#include <unordered_map>

namespace leetcode_1 {

// 方法一：暴力
// 执行用时：12 ms, 在所有 C++ 提交中击败了35.60%的用户
// 内存消耗：10.6 MB, 在所有 C++ 提交中击败了5.39%的用户
std::vector<int> twoSum_1(std::vector<int>& nums, int target)
{
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return std::vector<int>();
}

// 方法二：哈希表
// 执行用时：12 ms, 在所有 C++ 提交中击败了35.60%的用户
// 内存消耗：10.6 MB, 在所有 C++ 提交中击败了5.39%的用户
std::vector<int> twoSum_2(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> map;
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        auto it = map.find(target - nums[i]);
        if (it != map.end()) {
            return {it->second, i};
        } else {
            map.insert(std::pair<int, int>(nums[i], i));
        }
    }
    return {};
}


// =================================================================


class TwoSumTest : public testing::Test
{
public:
    virtual void SetUp() {
        twoSum = &twoSum_2;
    }

    virtual void TearDown() {
    }

protected:
    std::vector<int> (*twoSum)(std::vector<int>& nums, int target);
};

TEST_F(TwoSumTest, test_1)
{
    std::vector<int> vec = {2, 7, 11, 15};
    std::vector<int> rst = twoSum(vec, 9);
    ASSERT_EQ(2, rst.size());
    EXPECT_EQ(0, rst[0]);
    EXPECT_EQ(1, rst[1]);
}

TEST_F(TwoSumTest, test_2)
{
    std::vector<int> vec = {3, 2, 4};
    std::vector<int> rst = twoSum(vec, 6);
    ASSERT_EQ(2, rst.size());
    EXPECT_EQ(1, rst[0]);
    EXPECT_EQ(2, rst[1]);
}

TEST_F(TwoSumTest, test_3)
{
    std::vector<int> vec = {3, 3};
    std::vector<int> rst = twoSum(vec, 6);
    ASSERT_EQ(2, rst.size());
    EXPECT_EQ(0, rst[0]);
    EXPECT_EQ(1, rst[1]);
}

}