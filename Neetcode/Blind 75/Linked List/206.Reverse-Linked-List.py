from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = None

        while head:
            temp = head.next
            head.next = node
            node = head
            head = temp

        return node


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

    head = create_linked_list([1, 2, 3])
    result = sol.reverseList(head)
    print_linked_list(result)
