
#include "gtest/gtest.h"
#include <vector>

namespace leetcode_4 {

// 方法一： STL排序法
// 执行用时：40 ms, 在所有 C++ 提交中击败了68.73%的用户
// 内存消耗：87.8 MB, 在所有 C++ 提交中击败了5.74%的用户
double findMedianSortedArrays_1(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::vector<int> res;
    std::copy(nums1.begin(), nums1.end(), std::back_inserter(res));
    std::copy(nums2.begin(), nums2.end(), std::back_inserter(res));
    std::sort(res.begin(), res.end());

    if (res.size() % 2 == 0) {
        int mid = res.size() / 2;
        return (res[mid] + res[mid - 1]) / (double)2;
    } else {
        return res[res.size() / 2];
    }
}


// =================================================================


class MedianOfTwoSortedArraysTest : public testing::Test
{
public:
    virtual void SetUp() {
        findMedianSortedArrays = &findMedianSortedArrays_1;
    }

    virtual void TearDown() {
    }

protected:
    double (*findMedianSortedArrays)(std::vector<int>& nums1, std::vector<int>& nums2);
};

TEST_F(MedianOfTwoSortedArraysTest, test_1)
{
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    double rst = findMedianSortedArrays(nums1, nums2);
    EXPECT_EQ(2.00000, rst);
}

TEST_F(MedianOfTwoSortedArraysTest, test_2)
{
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    double rst = findMedianSortedArrays(nums1, nums2);
    EXPECT_EQ(2.50000, rst);
}

TEST_F(MedianOfTwoSortedArraysTest, test_3)
{
    std::vector<int> nums1 = {0, 0};
    std::vector<int> nums2 = {0, 0};
    double rst = findMedianSortedArrays(nums1, nums2);
    EXPECT_EQ(0.00000, rst);
}

TEST_F(MedianOfTwoSortedArraysTest, test_4)
{
    std::vector<int> nums1 = {};
    std::vector<int> nums2 = {1};
    double rst = findMedianSortedArrays(nums1, nums2);
    EXPECT_EQ(1.00000, rst);
}

TEST_F(MedianOfTwoSortedArraysTest, test_5)
{
    std::vector<int> nums1 = {2};
    std::vector<int> nums2 = {};
    double rst = findMedianSortedArrays(nums1, nums2);
    EXPECT_EQ(2.00000, rst);
}

}


