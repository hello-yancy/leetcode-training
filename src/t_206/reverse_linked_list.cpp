#include "reverse_linked_list.h"

class ReverseLinkedListImpl_1 : public ReverseLinkedList
{
public:
    // 执行用时：12 ms, 在所有 C++ 提交中击败了18.12%的用户
    // 内存消耗：8.2 MB, 在所有 C++ 提交中击败了24.23%的用户
    virtual ListNode* reverseList(ListNode* head)
    {
        ListNode* out = nullptr;
        for (ListNode* cur = head; cur != nullptr; cur=cur->next) {
            out = new ListNode(cur->val, out);
        }

        return out;
    }
};

class ReverseLinkedListImpl_2 : public ReverseLinkedList
{
public:
    // 执行用时：8 ms, 在所有 C++ 提交中击败了66.40%的用户
    // 内存消耗：8 MB, 在所有 C++ 提交中击败了72.59%的用户
    virtual ListNode* reverseList(ListNode* head)
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
};

std::shared_ptr<ReverseLinkedList> ReverseLinkedList::create(int type)
{
    switch (type) {
        case 1:
            return std::make_shared<ReverseLinkedListImpl_1>();
        case 2:
            return std::make_shared<ReverseLinkedListImpl_2>();
        default:
            return nullptr;
    }
}
