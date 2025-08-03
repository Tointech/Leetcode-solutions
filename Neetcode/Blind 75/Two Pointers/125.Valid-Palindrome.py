class Solution:
    def isPalindrome1(self, s: str) -> bool:
        s = "".join(c.lower() for c in s if c.isalnum())

        if s == s[::-1]:
            return True

        return False

    def isPalindrome2(self, s: str) -> bool:
        s = "".join(c.lower() for c in s if c.isalnum())

        left = 0
        right = len(s) - 1

        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1

        return True


if __name__ == "__main__":
    sol = Solution()

    s = "A man, a plan, a canal: Panama"
    result = sol.isPalindrome2(s)
    print(result)
