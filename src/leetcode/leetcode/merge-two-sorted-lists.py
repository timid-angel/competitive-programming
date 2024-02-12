# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        head = None
        if list1 and list2:
            if list1.val < list2.val:
                head = list1
                list1 = list1.next
            else:
                head = list2
                list2 = list2.next
        elif list1:
            head = list1
            list1 = list1.next
        elif list2:
            head = list2
            list2 = list2.next
        else:
            return head

        last = head
        while list1 and list2:
            if list1.val < list2.val:
                last.next = list1
                list1 = list1.next
                last = last.next
            else:
                last.next = list2
                list2 = list2.next
                last = last.next
        
        while list1:
            last.next = list1
            list1 = list1.next
            last = last.next
        
        while list2:
            last.next = list2
            list2 = list2.next
            last = last.next
        
        return head