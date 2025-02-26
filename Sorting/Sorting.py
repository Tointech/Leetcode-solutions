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
    
if __name__ == "__main__":
    sol = Sorting()

    arr = [2,1,10,23,20,3,9,7]
    print(sol.bubble_sort(arr))
