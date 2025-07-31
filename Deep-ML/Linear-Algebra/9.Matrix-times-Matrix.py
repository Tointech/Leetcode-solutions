import numpy as np
import torch


# TODO: Numpy library
def matrixmul_numpy(
    a: list[list[int | float]], b: list[list[int | float]]
) -> list[list[int | float]]:
    if len(a[0]) != len(b):
        return -1

    return np.dot(a, b).tolist()


# TODO: Torch library
import torch


def matrixmul_pytorch(a, b) -> torch.Tensor:
    """
    Multiply two matrices using PyTorch.
    Inputs can be Python lists, NumPy arrays, or torch Tensors.
    Returns a 2D tensor of shape (m, n) or a scalar tensor -1 if dimensions mismatch.
    """
    a_t = torch.as_tensor(a)
    b_t = torch.as_tensor(b)
    # dimension mismatch
    if a_t.size(1) != b_t.size(0):
        return torch.tensor(-1)
    # matrix multiplication
    return a_t.matmul(b_t)


if __name__ == "__main__":
    A = [[1, 2], [2, 4]]
    B = [[2, 1], [3, 4]]

    result = matrixmul_pytorch(A, B)
    print(result)
