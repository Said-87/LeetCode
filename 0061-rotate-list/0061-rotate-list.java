class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        
        // Empty list or single node
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        // Find length and the last node
        int length = 1;
        ListNode tail = head;

        while (tail.next != null) {
            tail = tail.next;
            length++;
        }

        // Avoid unnecessary rotations
        k = k % length;

        if (k == 0) {
            return head;
        }

        // Make the list circular
        tail.next = head;

        // Find the new tail
        int stepsToNewTail = length - k;

        ListNode newTail = head;

        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail.next;
        }

        // New head comes after the new tail
        ListNode newHead = newTail.next;

        // Break the circle
        newTail.next = null;

        return newHead;
    }
}