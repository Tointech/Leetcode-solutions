import numpy as np
import torch


# TODO: Numpy version
def scalar_multiply_numpy(
    matrix: list[list[int | float]], scalar: int | float
) -> list[list[int | float]]:
    return np.array(matrix) * scalar


# TODO: Pytorch
def scalar_multiply(matrix, scalar) -> torch.Tensor:
    """
    Multiply each element of a 2D matrix by a scalar using PyTorch.
    Inputs can be Python lists, NumPy arrays, or torch Tensors.
    Returns a 2D tensor of the same shape.
    """
    # Convert input to tensor
    m_t = torch.as_tensor(matrix, dtype=torch.float)
    # Your implementation here
    return m_t * scalar


if __name__ == "__main__":
    matrix = [[1, 2], [3, 4]]
    scalar = 2

    result = scalar_multiply_numpy(matrix, scalar)
    print(result)
