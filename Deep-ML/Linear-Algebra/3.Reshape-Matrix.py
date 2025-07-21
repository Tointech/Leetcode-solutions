from typing import List, Union
import numpy as np 

def reshape_matrix(a: list[list[int|float]], new_shape: tuple[int, int]) -> list[list[int|float]]:
    a = np.array(a)
    reshaped_matrix = a.reshape(new_shape)
    return reshaped_matrix.tolist()
        
if __name__ == "__main__":
    a = [[1,2,3,4],[5,6,7,8]]
    new_shape = (4, 2)
    ans = reshape_matrix(a, new_shape)
    
    print(ans)