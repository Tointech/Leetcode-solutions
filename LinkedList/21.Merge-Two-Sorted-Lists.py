from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 or not list2:
            return list2 or list1
        
        if list1.val <= list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2

def create_linked_list(values):
    if not values:
        return None
    
    head = ListNode(values[0])
    current = head

    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next

    return head 
    
def print_linked_list(node):
    values = []

    while node:
        values.append(str(node.val))
        node = node.next

    print(" -> ".join(values))

if __name__ == "__main__":
    sol = Solution()
    list1 = create_linked_list([1, 2, 4])
    list2 = create_linked_list([])
    print_linked_list(list1)
    print_linked_list(list2)

    result = sol.mergeTwoLists(list1, list2)
    print_linked_list(result)