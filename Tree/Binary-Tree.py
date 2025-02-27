from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# In-order DFS: Left, Root, Right
def in_order_dfs(node):
    if node is None:
        return
    in_order_dfs(node.left)
    print(node.data, end=' ')
    in_order_dfs(node.right)

# Pre-order DFS: Root, Left, Right
def pre_order_dfs(node):
    if node is None:
        return
    print(node.data, end=' ')
    pre_order_dfs(node.left)
    pre_order_dfs(node.right)

# Post-order DFS: Left, Right, Root
def post_order_dfs(node):
    if node is None:
        return
    post_order_dfs(node.left)
    post_order_dfs(node.right)
    print(node.data, end=' ')

# BFS: Level order traversal
def bfs(root):
    if root is None:
        return
    queue = [root]
    while queue:
        node = queue.pop(0)
        print(node.data, end=' ')
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

# Function to insert a new node in the binary tree
def insert(root, key):
    if root is None:
        return Node(key)

    # Create a queue for level order traversal
    queue = deque([root])

    while queue:
        temp = queue.popleft()

        # If left child is empty, insert the new node here
        if temp.left is None:
            temp.left = Node(key)
            break
        else:
            queue.append(temp.left)

        # If right child is empty, insert the new node here
        if temp.right is None:
            temp.right = Node(key)
            break
        else:
            queue.append(temp.right)

    return root

# In-order traversal
def inorder(root):
    if root is None:
        return
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)

# Function to search for a value in the binary tree using DFS
def searchDFS(root, value):
    # Base case: If the tree is empty or we've reached a leaf node
    if root is None:
        return False
    # If the node's data is equal to the value we are searching for
    if root.data == value:
        return True
    # Recursively search in the left and right subtrees
    left_res = searchDFS(root.left, value)
    right_res = searchDFS(root.right, value)

    return left_res or right_res

# Function to delete a node from the binary tree
def deleteNode(root, val):
    if root is None:
        return None

    # Use a queue to perform BFS
    queue = deque([root])
    target = None

    # Find the target node
    while queue:
        curr = queue.popleft()

        if curr.data == val:
            target = curr
            break
        if curr.left:
            queue.append(curr.left)
        if curr.right:
            queue.append(curr.right)

    if target is None:
        return root

    # Find the deepest rightmost node and its parent
    last_node = None
    last_parent = None
    queue = deque([(root, None)])

    while queue:
        curr, parent = queue.popleft()
        last_node = curr
        last_parent = parent

        if curr.left:
            queue.append((curr.left, curr))
        if curr.right:
            queue.append((curr.right, curr))

    # Replace target's value with the last node's value
    target.data = last_node.data

    # Remove the last node
    if last_parent:
        if last_parent.left == last_node:
            last_parent.left = None
        else:
            last_parent.right = None
    else:
        return None
    return root

if __name__ == "__main__":
    # Creating the tree
    root = Node(2)
    root.left = Node(3)
    root.right = Node(4)
    root.left.left = Node(5)

    print("In-order DFS: ", end='')
    in_order_dfs(root)
    print("\nPre-order DFS: ", end='')
    pre_order_dfs(root)
    print("\nPost-order DFS: ", end='')
    post_order_dfs(root)
    print("\nLevel order: ", end='')
    bfs(root)

    print("Inorder traversal before insertion: ", end="")
    inorder(root)
    print()

    key = 6
    root = insert(root, key)

    print("Inorder traversal after insertion: ", end="")
    inorder(root)
    print()

    value = 6
    if searchDFS(root, value):
        print(f"{value} is found in the binary tree")
    else:
        print(f"{value} is not found in the binary tree")

    val_to_del = 3
    root = deleteNode(root, val_to_del)

    print(f"Tree after deleting {val_to_del} (in-order): ", end="")
    inorder(root)
    print()