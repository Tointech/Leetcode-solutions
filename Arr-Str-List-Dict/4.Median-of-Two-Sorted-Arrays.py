from typing import List

class Solution:
    # Merge and Sort: O((n+m) * log(n+m))
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merge = sorted(nums1 + nums2)
        print(merge)

        l = len(merge)
        c = l // 2 # floor
        print(c)

        if l % 2 == 0:
            return (merge[c-1] + merge[c])/2
        return merge[c]

if __name__ == "__main__":
    sol = Solution()

    nums1 = [1, 3]
    nums2 = [2, 7]

    result = sol.findMedianSortedArrays(nums1, nums2)
    print(result)
