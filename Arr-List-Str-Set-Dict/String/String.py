# 1. Create a string
name = "Python"
print(name)

# 2. Accessing Characters in a String
print(name[0])

# 3. Joining Strings
first_name = "John"
last_name = "Doe"
full_name = first_name + " " + last_name
print(full_name)

# 4. Lenght of a String
print(len(name))

# 5. Iterating Over a String
for char in name:
    print(char)

# 6. String membership
print('P' in name)

class Solution:
    def reverseString(self, s: str) -> str:
        return s[::-1]

    def isBinary(self, s) -> bool:
        for c in s:
            if c not in '10':
                return False
        
        return True


if __name__ == "__main__":
    sol = Solution()
    
    s = "Hello"
    print(sol.reverseString(s)) # olleh

    binary = "101010"
    print(sol.isBinary(binary)) # True