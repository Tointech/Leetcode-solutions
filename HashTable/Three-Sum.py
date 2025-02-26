from typing import List 

class Solution:
    # Hash Table: O(n^3)
    def threeSum(self, nums:List[int], target:int) -> List[int]:
        n = len(nums)
 
        for i in range(n):
            rest = target - nums[i]

            if self.twoSum(nums, rest):
                return self.twoSum(nums, rest) + [i]
        
        return []
    

    def twoSum(self, nums:List[int], target:int) -> List[int]:
        n = len(nums)

        numDict = {}

        for i in range(len(nums)):
            rest = target - nums[i]

            if rest in numDict:
                return [numDict[rest], i]
            else:
                numDict[nums[i]] = i
        
        return []

if __name__ == "__main__":
    nums = [3,2,5,1,8]
    target = 9

    sol = Solution()
    result = sol.threeSum(nums, target) 
    print(result)
