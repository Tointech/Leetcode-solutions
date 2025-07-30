import numpy as np
import torch


# TODO: Numpy library
def inverse_2x2_numpy(matrix: list[list[float]]) -> list[list[float]]:
    # Check if matrix is invertible
    if np.linalg.det(matrix) == 0:
        return None

    inversed_matrix = np.linalg.inv(matrix)
    return inversed_matrix.tolist()


# TODO: Pytorch library


def inverse_2x2_torch(matrix) -> torch.Tensor | None:
    """
    Compute inverse of a 2Ã2 matrix using PyTorch.
    Input can be Python list, NumPy array, or torch Tensor.
    Returns a 2Ã2 tensor or None if the matrix is singular.
    """
    m = torch.as_tensor(matrix, dtype=torch.float)
    # Your implementation here

    if torch.linalg.det(m) == 0:
        return None

    inversed_matrix = torch.linalg.inv(m)

    return inversed_matrix


if __name__ == "__main__":
    # Example usage
    matrix = [[4, 7], [2, 6]]
    result = inverse_2x2_torch(matrix)

    print(result)
