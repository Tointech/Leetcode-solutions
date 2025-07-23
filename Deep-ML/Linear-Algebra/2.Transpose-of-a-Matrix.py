from typing import List, Union


def transpose_matrix(a: list[list[int | float]]) -> list[list[int | float]]:
    ans = []

    # zip(a): ([1, 2, 3],) ([4, 5, 6],) None
    # zip(*a): (1, 4) (2, 5) (3, 6) None
    for i in zip(*a):
        ans.append(list(i))

    return ans


# TODO: Library usage version
import numpy as np


def transpose_matrix_library(a):
    a = np.array(a)
    transposed = np.transpose(a)  # or a.T
    return transposed.tolist()


# TODO: Pytorch version
import torch


def transpose_matrix_torch(a) -> torch.Tensor:
    """
    Transpose a 2D matrix `a` using PyTorch.
    Inputs can be Python lists, NumPy arrays, or torch Tensors.
    Returns a transposed tensor.
    """
    a_t = torch.as_tensor(a)
    # Your implementation here
    return torch.transpose(a_t, 0, 1)


if __name__ == "__main__":
    a = [[1, 2, 3], [4, 5, 6]]
    ans = transpose_matrix_library(a)

    print(ans)
