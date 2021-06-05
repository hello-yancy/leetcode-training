
#include "gtest/gtest.h"
#include <vector>

namespace leetcode_2 {

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 方法一：链表模拟
// 执行用时：44 ms, 在所有 C++ 提交中击败了45.57%的用户
// 内存消耗：69.5 MB, 在所有 C++ 提交中击败了34.83%的用户
ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2)
{
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int v1 = l1 != nullptr ? l1->val : 0;
        int v2 = l2 != nullptr ? l2->val : 0;
        int sum = v1 + v2 + carry;

        carry = sum / 10;
        sum = sum % 10;

        if (head == nullptr) {
            head = new ListNode(sum);
            tail = head;
        } else {
            tail->next = new ListNode(sum);
            tail = tail->next;
        }
        
        if (l1 != nullptr) {
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            l2 = l2->next;
        }
    }

    if (carry > 0) {
        tail->next = new ListNode(carry);
    }

    return head;
}


// =================================================================


class AddTwoNumbersTest : public testing::Test
{
public:
    virtual void SetUp() {
        addTwoNumbers = &addTwoNumbers_1;
    }

    virtual void TearDown() {
    }

    ListNode* makeList(std::vector<int>& nodes) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for (auto n : nodes) {
            if (head == nullptr) {
                head = new ListNode(n);
                tail = head;
            } else {
                tail->next = new ListNode(n);
                tail = tail->next;
            }
        }
        return head;
    }

protected:
    ListNode* (*addTwoNumbers)(ListNode* l1, ListNode* l2);
};

TEST_F(AddTwoNumbersTest, test_1)
{
    std::vector<int> arr1 = {2, 4, 3};
    std::vector<int> arr2 = {5, 6, 4};
    ListNode* l1 = makeList(arr1);
    ListNode* l2 = makeList(arr2);

    ListNode* rst = addTwoNumbers(l1, l2);

    EXPECT_EQ(7, rst->val);
    EXPECT_EQ(0, rst->next->val);
    EXPECT_EQ(8, rst->next->next->val);
}

TEST_F(AddTwoNumbersTest, test_2)
{
    std::vector<int> arr1 = {0};
    std::vector<int> arr2 = {0};
    ListNode* l1 = makeList(arr1);
    ListNode* l2 = makeList(arr2);

    ListNode* rst = addTwoNumbers(l1, l2);

    EXPECT_EQ(0, rst->val);
}

TEST_F(AddTwoNumbersTest, test_3)
{
    std::vector<int> arr1 = {9, 9, 9, 9, 9, 9, 9};
    std::vector<int> arr2 = {9, 9, 9, 9};
    ListNode* l1 = makeList(arr1);
    ListNode* l2 = makeList(arr2);

    ListNode* rst = addTwoNumbers(l1, l2);

    EXPECT_EQ(8, rst->val); rst = rst->next;
    EXPECT_EQ(9, rst->val); rst = rst->next;
    EXPECT_EQ(9, rst->val); rst = rst->next;
    EXPECT_EQ(9, rst->val); rst = rst->next;
    EXPECT_EQ(0, rst->val); rst = rst->next;
    EXPECT_EQ(0, rst->val); rst = rst->next;
    EXPECT_EQ(0, rst->val); rst = rst->next;
    EXPECT_EQ(1, rst->val);
}

}
