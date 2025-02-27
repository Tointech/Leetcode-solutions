from typing import List

class Sorting():
    # O(n^2)
    def bubble_sort(self, arr: List[int]) -> List[int]:
        n = len(arr)

        for i in range(n-1):
            for j in range(i, n):
                if arr[j] < arr[i]:
                    temp = arr[i]
                    arr[i] = arr[j]
                    arr[j] = temp

        return arr
    
    # O(nlogn)
    def merge_sort(self, arr):
        if len(arr) <= 1:
            return arr  # Base case: already sorted

        # Step 1: Split the array into two halves
        mid = len(arr) // 2
        left_half = self.merge_sort(arr[:mid])
        right_half = self.merge_sort(arr[mid:])

        # Step 2: Merge the sorted halves
        return self.merge(left_half, right_half)

    def merge(left, right):
        merged = []
        i = j = 0

        # Merge elements in sorted order
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                merged.append(left[i])
                i += 1
            else:
                merged.append(right[j])
                j += 1

        # Append remaining elements (if any)
        merged.extend(left[i:])
        merged.extend(right[j:])
        
        return merged
    
    # O(nlogn)
    def quick_sort(self, arr):
        if len(arr) <= 1:
            return arr  # Base case: already sorted

        pivot = arr[len(arr) // 2]  # Choose the middle element as the pivot
        left = [x for x in arr if x < pivot]   # Elements smaller than pivot
        middle = [x for x in arr if x == pivot]  # Elements equal to pivot
        right = [x for x in arr if x > pivot]   # Elements greater than pivot

        return self.quick_sort(left) + middle + self.quick_sort(right)
    
if __name__ == "__main__":
    sol = Sorting()

    arr = [2,1,10,23,20,3,9,7]
    print(sol.bubble_sort(arr))
