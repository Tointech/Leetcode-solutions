from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        currentSum = nums[0]

        for num in nums[1:]:
            currentSum = max(currentSum + num, num)
            maxSum = max(maxSum, currentSum)

        return maxSum
    
if __name__ == "__main__":
    sol = Solution()
    nums = [-2,1,-3,4,-1,2,1,-5,4,-5,6,1]

    result = sol.maxSubArray(nums) 
    print(result)