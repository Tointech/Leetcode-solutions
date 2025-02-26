class Solution:
    # Brute force: O(n^2)
    def longestSubStringNoDuplicate1(self, s: str) -> str:
        longestStr = ""

        for i in range(len(s)):
            currentStr = ""
            
            for j in range(i, len(s)):
                if s[j] not in currentStr:
                    currentStr += s[j]
                else:
                    break      

            if len(currentStr) > len(longestStr):
                longestStr = currentStr

        return longestStr, len(longestStr)

    # Sliding window: O(n)
    def longestSubStringNoDuplicate2(self, s: str) -> str:
        left = 0
        right = 0
        longestStr = ""
        currentStr = ""

        while right < len(s)-1:
            if s[right] not in currentStr:
                currentStr += s[right]
            else:
                if len(currentStr) > len(longestStr):
                    longestStr = currentStr
                left += 1
            
            right += 1
            currentStr = s[left:right]
        return longestStr, len(longestStr)


if __name__ == "__main__":
    sol = Solution()

    s = "abcdabad"
    print(sol.longestSubStringNoDuplicate2(s))
