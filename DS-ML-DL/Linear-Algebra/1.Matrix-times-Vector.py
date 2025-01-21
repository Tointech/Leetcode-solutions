from typing import List, Union

def matrix_dot_vector(a:list[list[int,float]], b:list[int,float]) -> list[int,float]:
    if len(a[0]) != len(b):
        return -1
    
    ans = []

    for row in a:
        sum = 0
        for i in range(len(b)):
            sum += row[i] * b[i]
        
        ans.append(sum)

    return ans

# Library usage version
import numpy as np 

def library(a, b):
    a = np.array(a)
    b = np.array(b)

    if a.shape[1] != b.shape[0]: 
        return -1
    
    return np.dot(a, b).tolist()

if __name__ == "__main__":
    a = [[1, 2, 3], [4, 5, 6]] # a.shape[0] = 2, a.shape[1] = 3
    b = [7, 8, 9]
    ans = library(a, b)
    
    print(ans)