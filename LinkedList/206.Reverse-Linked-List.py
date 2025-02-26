from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head

        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        return prev
    
def create_linked_list(arr):
    if not arr:
        return None
    
    head = ListNode(arr[0])
    curr = head

    for val in arr[1:]:
        curr.next = ListNode(val)
        curr = curr.next 

    return head

def print_linked_list(head):
    curr = head

    while curr:
        print(curr.val, end="->")
        curr = curr.next

    print("None")

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]
    head = create_linked_list(arr)
    print_linked_list(head)

    sol = Solution()
    print_linked_list(sol.reverseList(head))