# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode | None) -> ListNode | None:
        dummy = ListNode(0, head)
        prev = dummy
        
        while head:
            # Check if this is the start of a duplicate sequence
            if head.next and head.val == head.next.val:
                # Skip all nodes with the duplicate value
                while head.next and head.val == head.next.val:
                    head = head.next
                # Stitch prev around all duplicates
                prev.next = head.next
            else:
                # No duplicate found, safe to move prev forward
                prev = prev.next
                
            head = head.next
            
        return dummy.next