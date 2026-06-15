# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next is None:
            return None

        self.delet([head], head)

        return head

    def delet(self, head_ref, h):

        if h is None or h.next is None:
            head_ref[0] = head_ref[0].next
        else:
            next_ref = [head_ref[0].next]
            self.delet(next_ref, h.next.next)
            head_ref[0].next = next_ref[0]
