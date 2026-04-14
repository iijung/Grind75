#include <list>
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include "solution.cpp"

static bool isSorted(ListNode* curr) {
    while (curr && curr->next) {
        if (curr->val > curr->next->val)
            return false;
        curr = curr->next;
    }
    return true;
}

static bool merge_test(vector<int> list1, vector<int> list2) {
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
    for (int i = list1.size() - 1; i >= 0; i--)
        l1 = new ListNode(list1[i], l1);
    for (int i = list2.size() - 1; i >= 0; i--)
        l2 = new ListNode(list2[i], l2);
    ListNode* l3 = Solution().mergeTwoLists(l1, l2);
    int result = isSorted(l3);
    while (l3 != nullptr) {
        ListNode* temp = l3->next;
        delete l3;
        l3 = temp;
    }
    return result;
}

int main() {
    assert(merge_test({1, 2, 4}, {1, 3, 4}));
    assert(merge_test({}, {}));
    assert(merge_test({}, {0}));
    assert(merge_test({1}, {}));
    return 0;
}
