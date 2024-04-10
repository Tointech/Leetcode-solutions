from typing import List
from collections import defaultdict

class Solution:
    # Hash Map: O(n)
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        m = defaultdict(int)

        for num in nums:
            m[num] += 1

        c = n // 2
        for key, value in m.items():
            if value > c:
                return key

        return 0

if __name__ == "__main__":
    sol = Solution()

    nums = [3, 2, 3]
    
    result = sol.majorityElement(nums)

    print(result)