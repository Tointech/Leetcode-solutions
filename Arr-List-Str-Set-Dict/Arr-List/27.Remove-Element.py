from typing import List

class Solution:
    # Array: O(n) = 38ms
    def removeElement(self, nums:List[int], val:int) -> int:
        k = 0
        n = len(nums)

        for i in range(n):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k

if __name__ == "__main__":
    sol = Solution()

    nums = [0,1,2,2,3,0,4,2]
    val = 2
    # i=0, k=0, [0,1,2,2,3,0,4,2]
    # i=1, k=1, [0,1,2,2,3,0,4,2]
    # i=2, k=2
    # i=3, k=2
    # i=4, k=2, [0,1,3,2,3,0,4,2]
    # i=5, k=3, [0,1,3,0,3,0,4,2]
    k = sol.removeElement(nums, val)
    print(k)
