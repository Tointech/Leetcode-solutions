import numpy as np
import torch


# TODO: Numpy version
def calculate_matrix_mean_numpy(matrix: list[list[float]], mode: str) -> list[float]:
    if mode == "column":
        return np.mean(matrix, axis=0).tolist()
    elif mode == "row":
        return np.mean(matrix, axis=1).tolist()


# TODO: Pytorch
def calculate_matrix_mean_torch(matrix, mode: str) -> torch.Tensor:
    """
    Calculate mean of a 2D matrix per row or per column using PyTorch.
    Inputs can be Python lists, NumPy arrays, or torch Tensors.
    Returns a 1-D tensor of means or raises ValueError on invalid mode.
    """
    a_t = torch.as_tensor(matrix, dtype=torch.float)
    # Your implementation here
    if mode == "column":
        return a_t.mean(dim=0)
    elif mode == "row":
        return a_t.mean(dim=1)


if __name__ == "__main__":
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    mode = "column"  # or "column"

    mean_values = calculate_matrix_mean_torch(matrix, mode)
    print(f"Mean values by {mode}: {mean_values}")
