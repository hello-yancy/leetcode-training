
#include "gtest/gtest.h"

namespace leetcode_206 {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList_1(ListNode* head)
{
    ListNode* out = nullptr;
    for (ListNode* cur = head; cur != nullptr; cur=cur->next) {
        out = new ListNode(cur->val, out);
    }

    return out;
}

ListNode* reverseList_2(ListNode* head)
{
    ListNode* out = nullptr;
    ListNode* next = nullptr;
    for (ListNode* cur = head; cur != nullptr; cur=next) {
        next = cur->next;
        cur->next = out;
        out = cur;
    }

    return out;
}


// =================================================================


class ReverseLinkedListTest : public testing::Test
{
public:
    virtual void SetUp() {
        reverseList = &reverseList_1;
    }

    virtual void TearDown() {
    }

    ListNode* make_list(const std::vector<int>& vec) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            if (head == nullptr) {
                head = new ListNode(*it);
                tail = head;
            } else {
                tail->next = new ListNode(*it);
                tail = tail->next;
            }
        }
        return head;
    }

protected:
    ListNode* (*reverseList)(ListNode* head);
};

TEST_F(ReverseLinkedListTest, test_1)
{
    ListNode* in = make_list({1, 2, 3, 4, 5});
    ListNode* rst = reverseList(in);
    ASSERT_NE(nullptr, rst);
    ASSERT_EQ(5, rst->val);
    ASSERT_EQ(4, rst->next->val);
    ASSERT_EQ(3, rst->next->next->val);
    ASSERT_EQ(2, rst->next->next->next->val);
    ASSERT_EQ(1, rst->next->next->next->next->val);
}

TEST_F(ReverseLinkedListTest, test_2)
{
    ListNode* in = make_list({1, 2});
    ListNode* rst = reverseList(in);
    ASSERT_NE(nullptr, rst);
    ASSERT_EQ(2, rst->val);
    ASSERT_EQ(1, rst->next->val);
}

TEST_F(ReverseLinkedListTest, test_3)
{
    ListNode* in = make_list({});
    ListNode* rst = reverseList(in);
    ASSERT_EQ(nullptr, rst);
}

}