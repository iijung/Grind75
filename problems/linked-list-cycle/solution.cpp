// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> visited;
        while (head) {
            visited.push_back(head);
            if (find(visited.begin(), visited.end(), head->next) != visited.end())
                return true;
            head = head->next;
        }
        return false;
    }
};
