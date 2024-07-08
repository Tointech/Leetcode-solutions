from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []

        n, p, z = [], [], []
        for num in nums: 
            if num > 0:
                p.append(num)
            elif num < 0: 
                n.append(num)
            else:
                z.append(num)

        # Case 1: [0, 0, 0]
        if len(z) >= 3:
            ans.append([0, 0, 0])

        # Case 2: [n, 0, p] if -n = p
        N, P = set(n), set(p)
        if z:
            for num in P:
                if -num in N:
                    ans.append([-num, 0, num])

        # Case 3: [n, n, p] if n+n = -p 
        lenN = len(n)
        for i in range(lenN-1):
            for j in range(i+1, lenN):
                sumN = n[i] + n[j]
                if -sumN in p:
                    ans.append(sorted([n[i], n[j], -sumN]))

        # Case 4: [n, p, p] if p+p = -n 
        lenP = len(p)
        for i in range(lenP-1):
            for j in range(i+1, lenP):
                sumP = p[i] + p[j]
                if -sumP in n:
                    ans.append(sorted([p[i], p[j], -sumP]))

        return ans

if __name__ == "__main__":
    sol = Solution()
    nums = [-1,0,1,2,-1,-4]

    result = sol.threeSum(nums)
    print(result)
