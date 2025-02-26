from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)-1

        while (left <= right):
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1

        return -1
    
if __name__ == "__main__":
    sol = Solution()
    
    nums = [-1,0,3,5,9,12]
    target = 3

    print(sol.search(nums, target))