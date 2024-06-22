from typing import List

class Solution:
    # Brute Force: O(n^2)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)

        for i in range(n - 1):
            for j in range(i + 1, n):
                if (nums[i] + nums[j] == target):
                    return [i,j]
        
        return []


if __name__ == "__main__":
    sol = Solution()
    
    nums = [3,2,4,1,7]
    target = 6

    result = sol.twoSum(nums, target) 
    print(result)
