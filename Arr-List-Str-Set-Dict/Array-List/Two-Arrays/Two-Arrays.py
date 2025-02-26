from typing import List 

class Solution():
    def twoSum(self, nums1: List[int], nums2: List[int], target: int) -> List[int]:
        for num in nums1:
            if target - num in nums2:
                return [target-num, num]
            
        return []
    
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))
    
    def intersection2(self, nums1: List[int], nums2: List[int]) -> List[int]:
        i, j = 0, 0
        result = []

        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1

        return result


    def union(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) | set(nums2))
    
    def union2(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = nums1 + nums2
        return list(set(result))


    def merge(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return sorted(nums1 + nums2)
    
    def merge2(self, nums1: List[int], nums2: List[int]) -> List[int]:
        i, j = 0, 0
        mergedList = []

        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                mergedList.append(nums1[i])
                i += 1
            else:
                mergedList.append(nums2[j])
                j += 1
        
        mergedList.extend(nums1[i:])
        mergedList.extend(nums2[j:])

        return mergedList

    def smallest_difference(self, nums1: List[int], nums2: List[int]) -> List[int]:
        pair = []
        
        i, j = 0, 0
        min_diff = float("inf")
        
        while i < len(nums1) and j < len(nums2):
            diff = abs(nums1[i] - nums2[j])

            if diff < min_diff:
                min_diff = diff
                pair = [nums1[i], nums2[j]]
            
            if nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1

        return min_diff, pair

if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 2, 3, 4]
    nums2 = [4, 5, 6, 7]
    target = 8

    print(sol.twoSum(nums1, nums2, target))
    print(sol.intersection2(nums1, nums2))
    print(sol.union2(nums1, nums2))
    print(sol.merge2(nums1, nums2))
    print(sol.smallest_difference(nums1, nums2))