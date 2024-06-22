from typing import List 

class Solution:
    # Brute Force: O(n^2) = 1654 ms
    def twoSumBruteForce(self, nums:List[int], target:int) -> List[int]:
        n = len(nums)
 
        for i in range(n-1):
            for j in range (i+1,n):
                if nums[i] + nums[j] == target:
                    return [i,j]
        return []

    # Hash Table: O(n) = 54ms
    def twoSumHashTable(self, nums:List[int], target:int) -> List[int]:
        n = len(nums)
        pocket = {} # dict {key:value}

        # i = 0, restNum = 6 - 3 = 3, key 3 not in pocket -> pocket[nums[0]] = pocket[3] = 0 -> pocket = {3:0}
        # i = 1, restNum = 6 - 2 = 4, key 4 not in pocket, pocket[nums[1]] = pocket[2] = 1 -> pocket = {3:0, 2:1}
        # i = 2, restNum = 6 - 4 = 2, key 2 in pocket -> return [pocket[2], i] = return [1, 2]

        for i in range(n):
            restNum = target - nums[i]
            if restNum in pocket: # check key in dict
                return [pocket[restNum], i]
            pocket[nums[i]] = i
 
        return []


if __name__ == "__main__":
    # Inputs
    nums = [3,2,4]
    target = 6

    s = Solution()
    result = s.twoSumHashTable(nums, target) 
    print(result)
