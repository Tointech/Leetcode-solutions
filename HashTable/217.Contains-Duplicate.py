from typing import List

class Solution:
    # Sorting: O(nlogn)
    def containsDuplicate1(self, nums: List[int]) -> bool:
        nums.sort()

        for i in range(len(nums)-1):
            if (nums[i] == nums[i+1]):
                return True
        
        return False

    # Hash Set: O(n)
    def containsDuplicate2(self, nums: List[int]) -> bool:
        seen = set()

        for num in nums:
            if num in seen:
                return True
            seen.add(num)

        return False

    # Hash Map: O(n)
    def containsDuplicate3(self, nums: List[int]) -> bool:
        seen = {}

        for num in nums:
            if num in seen and seen[num] >= 1:
                return True

            seen[num] = seen.get(num, 0) + 1

        return False 

if __name__ == "__main__":
    sol = Solution()
    
    nums = [3,2,4,1,7,6,5]

    result = sol.containsDuplicate1(nums) 
    print(result)
