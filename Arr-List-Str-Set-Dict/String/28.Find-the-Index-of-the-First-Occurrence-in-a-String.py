class Solution:
    # TODO: Library usage
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

    # TODO: Normal
    def strStr1(self, haystack: str, needle: str) -> int:
        n = len(haystack) - len(needle) + 1

        for i in range(n):
            if haystack[i : i + len(needle)] == needle:
                return i

        return -1


if __name__ == "__main__":
    sol = Solution()
    haystack = "hello"
    needle = "ll"

    result = sol.strStr(haystack, needle)
    print(result)
