class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()  # Remove leading and trailing whitespace

        if not s:
            return 0

        sign = 1
        if s[0] == "-":
            sign = -1
            s = s[1:]
        elif s[0] == "+":
            s = s[1:]

        num = 0
        for char in s:
            if char.isdigit():
                num = num * 10 + int(char)
            else:
                break

        num *= sign
        if num < -(2**31):
            return -(2**31)
        if num > 2**31 - 1:
            return 2**31 - 1
        return num


if __name__ == "__main__":
    sol = Solution()
    s = " -042"

    result = sol.myAtoi(s)
    print(result)
