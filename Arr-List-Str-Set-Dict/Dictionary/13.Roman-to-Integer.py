class Solution:
    def romanToInt(self, s:str) -> int:
        romanDict = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        ans = 0
        n = len(s)

        for i in range(n):
            if i < n-1 and romanDict[s[i]] < romanDict[s[i+1]]:
                ans -= romanDict[s[i]]
            else:
                ans += romanDict[s[i]]

        return ans

if __name__ == "__main__":
    sol = Solution()

    s = "LVIII"
    result = sol.romanToInt(s)
    print(result)
