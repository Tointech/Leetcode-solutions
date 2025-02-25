class Solution:
    # Brute Force: O(N^3)
    def longestPalindrome(self, s:str) -> str:
        l = len(s)
        maxLen = 1
        maxStr = s[0]

        for i in range(l-1):
            for j in range(i+1, l):
                str = s[i:j+1]
                if maxLen < j-i+1 and str == str[::-1]:
                    maxLen = j-i+1
                    maxStr = s[i:j+1]

        return maxStr

if __name__ == "__main__":
    sol = Solution()
    s1 = "babb"

    result = sol.longestPalindrome(s1)
    print(result)
