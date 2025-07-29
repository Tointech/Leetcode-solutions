import numpy as np
import torch


# TODO: Numpy library
def transform_matrix_numpy(
    A: list[list[int | float]], T: list[list[int | float]], S: list[list[int | float]]
) -> list[list[int | float]]:
    A = np.array(A)
    T = np.array(T)
    S = np.array(S)

    # Check if T and S are square matrices
    if T.shape[0] != T.shape[1] or S.shape[0] != S.shape[1]:
        return -1

    # Check if T and S are invertible (def != 0)
    if np.linalg.det(T) == 0 or np.linalg.det(S) == 0:
        return -1

    T_inv = np.linalg.inv(T)
    transformed_matrix = T_inv @ A @ S

    return transformed_matrix.tolist()


# TODO: Pytorch library


def transform_matrix_torch(A, T, S) -> torch.Tensor:
    """
    Perform the change-of-basis transform T^-1 A S and round to 3 decimals using PyTorch.
    Inputs A, T, S can be Python lists, NumPy arrays, or torch Tensors.
    Returns a 2x2 tensor or tensor(-1.) if T or S is singular.
    """
    A_t = torch.as_tensor(A, dtype=torch.float)
    T_t = torch.as_tensor(T, dtype=torch.float)
    S_t = torch.as_tensor(S, dtype=torch.float)
    # Your implementation here

    if T_t.shape[0] != T_t.shape[1] or S_t.shape[0] != S_t.shape[1]:
        return torch.tensor(-1.0)

    if torch.linalg.det(T_t) == 0 or torch.linalg.det(S_t) == 0:
        return torch.tensor(-1.0)

    transformed_matrix = torch.linalg.inv(T_t) @ A_t @ S_t
    return transformed_matrix


if __name__ == "__main__":
    A = [[1, 2], [3, 4]]
    T = [[2, 0], [0, 2]]
    S = [[1, 1], [0, 1]]

    result = transform_matrix_torch(A, T, S)
    print(result)
