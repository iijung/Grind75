// https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
#if 0
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *const rtn = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rtn;
    }
#else
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *const next = curr->next;
            curr->next = new_head;
            new_head = curr;
            curr = next;
        }
        return new_head;
    }
#endif
};
