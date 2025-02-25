class Solution:
    def intToRoman(self, num: int) -> str:
        intDict = {
            1: "I", 4: "IV", 5: "V", 9: "IX",
            10: "X", 40: "XL", 50: "L", 90: "XC",
            100: "C", 400: "CD", 500: "D", 900: "CM",
            1000: "M",
        }

        ans = ""

        for n in [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]:
            while n <= num:
                ans += intDict[n]
                num -= n
        return ans

if __name__ == "__main__":
    sol = Solution()

    num = 58
    result = sol.intToRoman(num)
    print(result)
