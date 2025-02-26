from typing import List

class Solution:
    # Hash Table: O(n)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numDict = {}

        for i in range(len(nums)):
            rest = target - nums[i]
            if rest in numDict:
                return [numDict[rest], i]
            else:
                numDict[nums[i]] = i
        return []
    
if __name__ == "__main__":
    sol = Solution()

    nums = [2,7,11,15]
    target = 9
    print(sol.twoSum(nums, target))


# dict = {
#          2: 1}
#          7: 2}
# [2,7,11,15], target = 9