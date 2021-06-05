
#include "gtest/gtest.h"
#include <string>
#include <unordered_set>
#include <unordered_map>

namespace leetcode_3 {

// 方法一：滑动窗口，set.insert与right++为什么放在第二个while之后，想不清楚
// 执行用时：44 ms, 在所有 C++ 提交中击败了45.57%的用户
// 内存消耗：69.5 MB, 在所有 C++ 提交中击败了34.83%的用户
int lengthOfLongestSubstring_1(std::string s)
{
    int left = 0;
    int right = 0;
    int len = 0;
    std::unordered_set<int> set;
    while (right < s.length()) {
        while (set.count(s[right]) != 0) {
            set.erase(s[left]);
            left++;
        }
        len = std::max(len, right - left + 1);
        std::cout << s.substr(left, right - left + 1) << "," << left << "," << right << std::endl;
        set.insert(s[right]);
        right++;
    }
    
    return len;
}

// 方法二：滑动窗口，采用labuladong模板
// 执行用时：20 ms, 在所有 C++ 提交中击败了68.08%的用户
// 内存消耗：8.2 MB, 在所有 C++ 提交中击败了56.49%的用户
int lengthOfLongestSubstring_2(std::string s)
{
    int left = 0;
    int right = 0;
    int len = 0;
    std::unordered_map<char, int> wnd;
    while (right < s.length()) {
        char c = s[right];
        right++;

        // 隐藏了c不存在时的初始化
        wnd[c] += 1;
        // std::cout << "l=" << left << ",r=" << right << std::endl;

        while (wnd[c] > 1) {
            char d = s[left];
            left++;

            wnd[d] -= 1;
        }
        len = std::max(len, right - left);
    }
    return len;
}


// =================================================================


class LongestSubstringWithoutRepeatingCharactersTest : public testing::Test
{
public:
    virtual void SetUp() {
        lengthOfLongestSubstring = &lengthOfLongestSubstring_2;
    }

    virtual void TearDown() {
    }

protected:
    int (*lengthOfLongestSubstring)(std::string s);
};

TEST_F(LongestSubstringWithoutRepeatingCharactersTest, test_1)
{
    int rst = lengthOfLongestSubstring("abcabcbb");
    EXPECT_EQ(3, rst);
}

TEST_F(LongestSubstringWithoutRepeatingCharactersTest, test_2)
{
    int rst = lengthOfLongestSubstring("bbbbb");
    EXPECT_EQ(1, rst);
}

TEST_F(LongestSubstringWithoutRepeatingCharactersTest, test_3)
{
    int rst = lengthOfLongestSubstring("pwwkew");
    EXPECT_EQ(3, rst);
}

TEST_F(LongestSubstringWithoutRepeatingCharactersTest, test_4)
{
    int rst = lengthOfLongestSubstring("");
    EXPECT_EQ(0, rst);
}

}

