from typing import List

class Searching():
    # Unordered/ Ordered list: O(n)
    def linear_search(self, arr: List[int], target: int) -> int:
        for i in range(len(arr)):
            if arr[i] == target:
                return i
        return -1
    
    # Ordered list: Divide and Conquer O(logn) 
    def binary_search_recursive(self, arr: List[int], left:int, right:int, target: int) -> int:
        if left <= right:
            mid = (left + right) // 2

            if arr[mid] == target:
                return mid
            elif arr[mid] < target:
                return self.binary_search_recursive(arr, mid+1, right, target)
            else: 
                return self.binary_search_recursive(arr, left, mid-1, target)
        else:
            return -1
    
    def binary_search(self, arr: List[int], target: int) -> int:
        if sorted(arr) != arr:
            arr = sorted(arr)

        left = 0
        right = len(arr) - 1

        return self.binary_search_recursive(arr, left, right, target)


if __name__ == '__main__':
    searchAlg = Searching()
    
    arr = [4,5,6,7,0,1,2]

    print(searchAlg.linear_search(arr, 0))

    sorted_arr = [1, 3, 5, 6, 7, 8]
    print(searchAlg.binary_search(sorted_arr, 5))