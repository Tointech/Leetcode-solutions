class Solution:
    # Brute Force: O(N^2)
    def longestPalindrome1(self, s:str) -> str:
        longestStr = s[0]

        for i in range(len(s)-1):
            currentStr = ""

            for j in range(i, len(s)):
                currentStr = s[i:j+1]

                if currentStr == currentStr[::-1]:
                    if len(currentStr) > len(longestStr):
                        longestStr = currentStr
                else:
                    j += 1
        
        return longestStr


if __name__ == "__main__":
    sol = Solution()
    s1 = "babab"

    result = sol.longestPalindrome2(s1)
    print(result)
