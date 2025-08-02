from typing import List


class Solution:
    # Brute Force: O(n^2)
    def twoSum1(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)

        for i in range(0, n - 1):
            for j in range(i, n):
                if nums[i] + nums[j] == target:
                    return [i, j]

            return []

    # Hash Table: O(n)
    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        pocket = {}
        n = len(nums)

        for i in range(n):
            resNum = target - nums[i]
            if resNum in pocket:
                return [pocket[resNum], i]
            pocket[nums[i]] = i
        return []


if __name__ == "__main__":
    sol = Solution()

    nums = [2, 7, 11, 15]
    target = 9

    result = sol.twoSum2(nums, target)
    print(result)
