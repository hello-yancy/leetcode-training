#ifndef REVERSE_LINKED_LIST_H
#define REVERSE_LINKED_LIST_H

#include <memory>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReverseLinkedList
{
public:
    virtual ListNode* reverseList(ListNode* head) = 0;

    static std::shared_ptr<ReverseLinkedList> create(int tpye);
};

#endif