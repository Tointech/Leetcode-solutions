class Solution:
    def isValid(self, s:str) -> bool:
        pairs = {
            ")": "(",
            "]": "[",
            "}": "{",
        }

        stack = []

        for char in s:
            if char in "([{":
                stack.append(char)
            elif len(stack) == 0 or stack.pop() != pairs[char]:
                return False
        
        return len(stack) == 0
    

if __name__ == "__main__":
    sol = Solution()
    s = "]"

    result = sol.isValid(s)
    print(result)