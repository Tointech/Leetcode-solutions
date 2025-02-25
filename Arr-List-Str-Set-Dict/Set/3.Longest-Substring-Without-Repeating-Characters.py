class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLength = 0
        n = len(s)
        currentSet = set()
        j = 0

        for i in range(n):
            if s[i] not in currentSet:
                currentSet.add(s[i])
                maxLength = max(maxLength, i-j+1)
            else:
                while s[i] in currentSet:
                    currentSet.remove(s[j])
                    j += 1
                currentSet.add(s[i])

        return maxLength


if __name__ == "__main__":
    sol = Solution()

    s = "abcabca"

    result = sol.lengthOfLongestSubstring(s) 
    print(result)
