from typing import List 

class Solution:
    # Brute Force: O(n^3)
    def threeSum(self, nums:List[int], target:int) -> List[int]:
        n = len(nums)
 
        for i in range(n-2):
            for j in range (i+1,n-1):
                for k in range (j+1, n):
                    if nums[i] + nums[j] + nums[k] == target:
                        return [i,j,k]

        return []

    #

if __name__ == "__main__":
    # Inputs
    nums = [3,2,5,1,8]
    target = 9

    sol = Solution()
    result = sol.threeSum(nums, target) 
    print(result)
