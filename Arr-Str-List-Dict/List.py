# 1. Creating a List
a = [1, 2, 3, 4, 5]

b = [2] * 5

c = [i for i in range(1, 6)]

print(a, b, c)

# 2. Accessing Elements
print(a[0], a[-1])

# 3. Adding Elements into List
d = []
d.append(10) # add to end of list
d.insert(0, 9) # insert 9 at index 0
d.extend([11, 12]) # add multiple elements 
print(d)

# 4. Update Elements
e = [10, 20, 20]
e[1] = 15
print(e)

# 5. Removing Elements
f = [10, 20, 30, 40]
f.pop() # remove last element
f.pop(1) # remove element at index 1
f.remove(10) # remove first occurrence of 10
print(f)

# 6. Iterating Over List
fruits = ['apple', 'banana', 'cherry']
for item in fruits:
    print(item)

# 7. Nested Lists
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
print(matrix[1][1])