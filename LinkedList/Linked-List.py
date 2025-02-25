from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


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
    list1 = create_linked_list([1, 2, 4])
    list2 = create_linked_list([1, 3, 4])
    print_linked_list(list1)
    print_linked_list(list2)