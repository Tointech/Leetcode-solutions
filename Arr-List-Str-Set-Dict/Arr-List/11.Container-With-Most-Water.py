from typing import List

class Solution: 
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height)-1
        maxArea = 0

        while l < r:
            h = min(height[l], height[r])
            area = h * (r - l)
            if area > maxArea: 
                maxArea = area

            if height[l] < height[r]:
                l += 1
            else: 
                r -= 1

        return maxArea


if __name__ == "__main__":
    sol = Solution()
    height = [1,8,6,2,5,4,8,3,7]

    ans = sol.maxArea(height)
    print(ans)
