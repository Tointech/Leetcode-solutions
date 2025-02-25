from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        productExpectZero = 1
        countZero = 0

        for num in nums: 
            if num != 0:
                productExpectZero *= num
            else:
                countZero += 1
        
        ans = [0] * len(nums)

        for i in range(len(nums)):
            if countZero == 0:
                ans[i] = productExpectZero // nums[i]
            elif countZero == 1:
                if nums[i] == 0:
                    ans[i] = productExpectZero         

        return ans
    
if __name__ == "__main__":
    sol = Solution()
    nums = [1,2,3,4]

    print(sol.productExceptSelf(nums))