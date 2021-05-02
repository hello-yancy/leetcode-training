#include "reverse_linked_list.h"
#include "gtest/gtest.h"

#include <vector>

class ReverseLinkedListTest : public testing::Test
{
public:
    virtual void SetUp() {
        m_ptr = ReverseLinkedList::create(2);
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
    std::shared_ptr<ReverseLinkedList> m_ptr;
};

TEST_F(ReverseLinkedListTest, test_1)
{
    ListNode* in = make_list({1, 2, 3, 4, 5});
    ListNode* rst = m_ptr->reverseList(in);
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
    ListNode* rst = m_ptr->reverseList(in);
    ASSERT_NE(nullptr, rst);
    ASSERT_EQ(2, rst->val);
    ASSERT_EQ(1, rst->next->val);
}

TEST_F(ReverseLinkedListTest, test_3)
{
    ListNode* in = make_list({});
    ListNode* rst = m_ptr->reverseList(in);
    ASSERT_EQ(nullptr, rst);
}