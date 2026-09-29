class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        // Dummy node helps when left = 1
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Move prev to the node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr is the first node of the part to reverse
        ListNode* curr = prev->next;

        // Reverse nodes between left and right
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;

            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};