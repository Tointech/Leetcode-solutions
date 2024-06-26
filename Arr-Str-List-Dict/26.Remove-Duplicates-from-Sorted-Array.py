from typing import List 

class Solution:
    # Array: O(n) = 68ms
    def removeDuplicatesArray(self, nums:List[int]) -> int:
        k = 1
        n = len(nums)
 
        for i in range(1, n):
            if nums[i] != nums[i-1]:
                nums[k] = nums[i]
                k += 1
        return k

    # Set: O(n) = 74ms
    def removeDuplicatesSet(self, nums:List[int]) -> int:
        unique_nums = set()
        k = 0

        for num in nums:
            if num not in unique_nums:
                unique_nums.add(num)
                nums[k] = num
                k += 1

        return k

if __name__ == "__main__":
    sol = Solution()

    nums = [1,1,2,2,3,4,4,5]
    # i=1, k=1 -> nums[1] = nums[0]
    # i=2, k=1 -> nums[2] != nums[1] -> nums[1] = nums[2], [1,2,2,2,3,4,4,5], k=2
    # i=3, k=2 -> nums[3] = nums[2]
    # i=4, k=2 -> nums[4] != nums[3] -> nums[2] = nums[4], [1,2,3,2,3,4,4,5], k=3
    # i=5, k=3 -> nums[5] != nums[4] -> nums[3] = nums[5], [1,2,3,4,3,4,4,5], k=4
    # i=6, k=4 -> nums[6] = nums[5]
    # i=7, k=4 -> nums[7] != nums[6] -> nums[4] = nums[7], [1,2,3,4,5,4,4,5], k=5
    k = sol.removeDuplicatesArray(nums)
    print(k)
