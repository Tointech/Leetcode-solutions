import numpy as np


# TODO: Library usage version
def reshape_matrix_library(
    a: list[list[int | float]], new_shape: tuple[int, int]
) -> list[list[int | float]]:
    a = np.array(a)
    reshaped_matrix = a.reshape(new_shape)
    return reshaped_matrix.tolist()


# TODO: Pytorch version
import torch


def reshape_matrix_pytorch(a, new_shape) -> torch.Tensor:
    """
    Reshape a 2D matrix `a` to shape `new_shape` using PyTorch.
    Inputs can be Python lists, NumPy arrays, or torch Tensors.
    Returns a tensor of shape `new_shape`, or an empty tensor on mismatch.
    """
    # Dimension check
    if len(a) * len(a[0]) != new_shape[0] * new_shape[1]:
        return torch.tensor([])
    # Convert to tensor and reshape
    a_t = torch.as_tensor(a, dtype=torch.float)
    # Your implementation here
    return torch.reshape(a_t, new_shape)


if __name__ == "__main__":
    a = [[1, 2, 3, 4], [5, 6, 7, 8]]
    new_shape = (4, 2)
    ans = reshape_matrix_pytorch(a, new_shape)

    print(ans)
