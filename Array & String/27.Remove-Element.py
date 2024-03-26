from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        index = 0

        for i in range(len(nums)):
            if (nums[i] != val):
                nums[index] = nums[i]
                index += 1

        return index                

if __name__ == "__main__":
    sol = Solution()
    
    nums = [0,1,2,2,3,0,4,2]
    val = 0

    result = sol.removeElement(nums, val) 
    print(result)
