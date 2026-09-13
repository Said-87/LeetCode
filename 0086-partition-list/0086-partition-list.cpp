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

// I/O speedup for competitive programming / LeetCode test harnesses
static const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Stack-allocated sentinels avoid dynamic memory allocation (new/delete)
        ListNode before_dummy;
        ListNode after_dummy;

        ListNode* before = &before_dummy;
        ListNode* after = &after_dummy;

        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            if (curr->val < x) {
                before->next = curr;
                before = curr;
            } else {
                after->next = curr;
                after = curr;
            }
        }

        // Sever the remainder to prevent reference cycles
        after->next = nullptr;

        // Concatenate the two sublists
        before->next = after_dummy.next;

        return before_dummy.next;
    }
};

