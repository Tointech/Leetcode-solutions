# 1. Create a set
mixed_set = {'Hello', 101, -2, 'Bye'}
print('Set of mixed data types:', mixed_set)
print(type(mixed_set))

# 2. Create an empty set
empty_set = set()
print('Empty set:', empty_set)
print(type(empty_set))

# 3. Duplicate Items in a Set
numbers = {2, 4, 6, 6, 2, 8}
print(numbers)   # {8, 2, 4, 6}

# 4. Add Items to a Set
numbers.add(10)
print(numbers)   # {2, 4, 6, 8, 10}

# 5. Remove Items from a Set
numbers.remove(6)
print(numbers)   # {2, 4, 8, 10}