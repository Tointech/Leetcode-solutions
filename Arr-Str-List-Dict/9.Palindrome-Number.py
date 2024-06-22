class Solution:
    def isPalindrome(self, x: int) -> bool:
        x_str = str(x)
        x_reversed = x_str[::-1]

        return x_str == x_reversed
    
if __name__ == "__main__":
    sol = Solution()
    s = "-121"

    result = sol.isPalindrome(s) 
    print(result)