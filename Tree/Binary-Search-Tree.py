# Structure of a Binary Tree Node
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
        
def printInorder(root):
    if(root == None):
        return
    printInorder(root.left)
    print(root.data, end = " ")
    printInorder(root.right)

# A utility function to insert a new node with the given key
def insert(root, key):
    if root is None:
        return Node(key)
    if root.val == key:
            return root
    if root.val < key:
            root.right = insert(root.right, key)
    else:
            root.left = insert(root.left, key)
    return root

# function to search a key in a BST
def search(root, key):
  
    # Base Cases: root is null or key 
    # is present at root
    if root is None or root.key == key:
        return root
    
    # Key is greater than root's key
    if root.key < key:
        return search(root.right, key)
    
    # Key is smaller than root's key
    return search(root.left, key)

# A utility function to do inorder tree traversal
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=" ")
        inorder(root.right)

# Inorder Traversal
def printInorder(root):
    if root:
        # Traverse left subtree
        printInorder(root.left)
        
        # Visit node
        print(root.data,end=" ")
        
        # Traverse right subtree
        printInorder(root.right)

if __name__ == '__main__':
    
    # Construct Binary Search Tree of 4 nodes
    r = Node(15)
    r = insert(r, 10)
    r = insert(r, 18)
    r = insert(r, 4)
    r = insert(r, 11)
    r = insert(r, 16)
    r = insert(r, 20)
    r = insert(r, 13)

    # Print inorder traversal of the BST
    inorder(r)

    root = Node(50)
    root.left = Node(30)
    root.right = Node(70)
    root.left.left = Node(20)
    root.left.right = Node(40)
    root.right.left = Node(60)
    root.right.right = Node(80)

    # Searching for keys in the BST
    print("Found" if search(root, 19) else "Not Found")
    print("Found" if search(root, 80) else "Not Found")

    root = Node(100)
    root.left = Node(20)
    root.right = Node(200)
    root.left.left = Node(10)
    root.left.right = Node(30)
    root.right.left = Node(150)
    root.right.right = Node(300)

    # Function call
    print("Inorder Traversal:",end=" ")
    printInorder(root)