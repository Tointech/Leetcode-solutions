from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while (left <= right):
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid
            
            # Check if left is sorted
            if nums[left] <= nums[mid]:
                if nums[mid] > target >= nums[left]:
                    right = mid - 1
                else:
                    left = mid + 1
            
            # Check if right is sorted
            if nums[right] >= nums[mid]:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return -1

if __name__ == "__main__":
    sol = Solution()

    nums = [4,5,6,7,8,1,2,3]

    target = 8

    print(sol.search(nums, target))
        