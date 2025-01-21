from typing import List, Union

def transpose_matrix(a: list[list[int|float]]) -> list[list[int|float]]:   
    ans = []

    # zip(a): ([1, 2, 3],) ([4, 5, 6],) None
    # zip(*a): (1, 4) (2, 5) (3, 6) None
    for i in zip(*a):
        ans.append(list(i))

    return ans
        

# Library usage version
import numpy as np 

def library(a):
    a = np.array(a)
    tranposed = np.transpose(a) # or a.T
    return tranposed.tolist()


if __name__ == "__main__":
    a = [[1,2,3],[4,5,6]]
    ans = library(a)
    
    print(ans)