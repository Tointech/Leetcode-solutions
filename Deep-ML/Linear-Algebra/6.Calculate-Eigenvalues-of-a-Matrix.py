# Reasoning:
# The eigenvalues of a matrix are the values of λ for which the equation det(A - λI) = 0 has solutions.
# This is equivalent to finding the roots of the characteristic polynomial of the matrix.
# The eigenvalues can provide insights into the properties of the matrix, such as its stability and behavior under transformations.

import numpy as np
from numpy import linalg
import torch


# TODO: Numpy version
def calculate_eigenvalues_numpy(matrix: list[list[float | int]]) -> list[float]:
    matrix = np.array(matrix)
    eigenvalues, eigenvectors = linalg.eig(matrix)
    return eigenvalues


# TODO: Pytorch
def calculate_eigenvalues_torch(matrix: torch.Tensor) -> torch.Tensor:
    """
    Compute eigenvalues of a 2x2 matrix using PyTorch.
    Input: 2x2 tensor; Output: 1-D tensor with the two eigenvalues in ascending order.
    """
    # Your implementation here
    matrix = torch.as_tensor(matrix, dtype=torch.float)
    eigenvalues = torch.linalg.eigvals(matrix)
    eigenvalues = eigenvalues.real  # Take only the real part of eigenvalues

    return torch.sort(eigenvalues).values


if __name__ == "__main__":
    matrix = [[2, 1], [1, 2]]

    result = calculate_eigenvalues_torch(matrix)
    print(result)
