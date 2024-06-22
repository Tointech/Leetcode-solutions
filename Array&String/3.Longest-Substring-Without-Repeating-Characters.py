from typing import List

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLength = 0
        n = len(s)
        nSet = set()
        j = 0

        for i in range(n):
            if s[i] not in nSet:
                nSet.add(s[i])
                maxLength = max(maxLength, i-j+1)
            else:
                while s[i] in nSet:
                    nSet.remove(s[j])
                    j += 1
                nSet.add(s[i])

        return maxLength


if __name__ == "__main__":
    sol = Solution()
    
    s = "abcabca"

    result = sol.lengthOfLongestSubstring(s) 
    print(result)
