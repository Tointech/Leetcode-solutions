from typing import List

class Solution:
    # Linear Search: O(n) = 37ms
    def searchInsertLinear(self, nums: List[int], target:int) -> int:
        n = len(nums)

        for i in range(n):
            if nums[i] >= target:
                return i

        return n

    # Binary Serach: O(logn) = 48ms
    def searchInsertBinary(self, nums: List[int], target:int) -> int:
        left = 0
        right = len(nums)

        while left < right:
            mid = (left + right) // 2
            if target > nums[mid]:
                left = mid + 1
            else:
                right = mid

        return left

if __name__ == "__main__":
    sol = Solution()

    nums = [1,3,5,6]
    target = 5
    result = sol.searchInsertBinary(nums, target)
    print(result)
