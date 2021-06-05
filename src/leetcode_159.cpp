
#include "gtest/gtest.h"
#include <string>
#include <unordered_map>

namespace leetcode_159 {

// 方法一：滑动窗口
// 执行用时：16 ms, 在所有 C++ 提交中击败了48.78%的用户
// 内存消耗：7.6 MB, 在所有 C++ 提交中击败了51.21%的用户
int lengthOfLongestSubstringTwoDistinct_1(std::string s)
{
    int left = 0;
    int right = 0;
    int len = 0;
    std::unordered_map<char, int> wnd;

    while (right < s.size()) {
        if (wnd.count(s[right]) == 0) {
            wnd[s[right]] = 1;
        } else {
            wnd[s[right]] += 1;
        }

        while (wnd.size() > 2) {
            if (wnd[s[left]] > 1) {
                wnd[s[left]] -= 1;
            } else {
                wnd.erase(s[left]);
            }
            left++;
        }
        
        // std::cout << s.substr(left, right - left + 1) << "," << ",left=" << left << ",right=" << right << std::endl;
        len = std::max(len, right - left + 1);
        right++;
    }

    return len;
}


// 方法二：滑动窗口，采用labuladong模板
// 执行用时：16 ms, 在所有 C++ 提交中击败了48.78%的用户
// 内存消耗：7.6 MB, 在所有 C++ 提交中击败了61.55%的用户
int lengthOfLongestSubstringTwoDistinct_2(std::string s)
{
    int left = 0;
    int right = 0;
    int len = 0;
    std::unordered_map<char, int> wnd;

    while (right < s.length()) {
        char c = s[right];
        right++;

        wnd[c] += 1;
        while (wnd.size() > 2) {
            char d = s[left];
            left++;

            wnd[d] -= 1;
            if (wnd[d] == 0) {
                wnd.erase(d);
            }
        }
        len = std::max(len, right - left);
    }

    return len;
}

// =================================================================


class LongestSubstringWithAtMostTwoDistinctCharactersTest : public testing::Test
{
public:
    virtual void SetUp() {
        lengthOfLongestSubstringTwoDistinct = &lengthOfLongestSubstringTwoDistinct_2;
    }

    virtual void TearDown() {
    }

protected:
    int (*lengthOfLongestSubstringTwoDistinct)(std::string s);
};

TEST_F(LongestSubstringWithAtMostTwoDistinctCharactersTest, test_1)
{
    int rst = lengthOfLongestSubstringTwoDistinct("eceba");
    EXPECT_EQ(3, rst);
}

TEST_F(LongestSubstringWithAtMostTwoDistinctCharactersTest, test_2)
{
    int rst = lengthOfLongestSubstringTwoDistinct("ccaabbb");
    EXPECT_EQ(5, rst);
}

}

