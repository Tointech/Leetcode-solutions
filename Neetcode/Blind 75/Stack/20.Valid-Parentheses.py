class Solution:
    def isValid1(self, s: str) -> bool:
        pairs = {
            "(": ")",
            "{": "}",
            "[": "]",
        }

        stack = []
        for char in s:
            if char in pairs:
                stack.append(char)
            elif len(stack) != 0 and char == pairs[stack[-1]]:
                stack.pop()
            else:
                return False

        if len(stack) != 0:
            return False

        return True

    # Shorter version
    def isValid2(self, s: str) -> bool:
        pairs = {
            "(": ")",
            "{": "}",
            "[": "]",
        }
        stack = []

        for char in s:
            if char in pairs:
                stack.append(char)
            elif char in pairs.values():
                if not stack or char != pairs[stack.pop()]:
                    return False

        return not stack


if __name__ == "__main__":
    sol = Solution()

    s = "(())"
    result = sol.isValid2(s)
    print(result)
