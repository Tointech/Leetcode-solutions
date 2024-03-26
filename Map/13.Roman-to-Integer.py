class Solution:
    def romanToInt(self, s: str) -> int:
        # Unordered map
        m = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        ans = 0

        n = len(s)
        for i in range(n):
            if (i < n-1) and (m[s[i]] < m[s[i+1]]):
                ans -= m[s[i]]
            else:
                ans += m[s[i]]

        return ans

if __name__ == "__main__":
    sol = Solution()
    s = "MCMXCIV"

    result = sol.romanToInt(s) 
    print(result)
