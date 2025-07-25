import numpy as np
import torch


def matrix_dot_vector(
    a: list[list[int, float]], b: list[int, float]
) -> list[int, float]:
    if len(a[0]) != len(b):
        return -1

    ans = []

    for row in a:
        sum = 0
        for i in range(len(b)):
            sum += row[i] * b[i]

        ans.append(sum)

    return ans


# TODO: Numpy version


def matrix_dot_vector_numpy(a, b):
    a = np.array(a)
    b = np.array(b)

    if a.shape[1] != b.shape[0]:
        return -1

    return np.dot(a, b).tolist()


# TODO: Pytorch version


def matrix_dot_vector_torch(a, b) -> torch.Tensor:
    """
    Compute the product of matrix `a` and vector `b` using PyTorch.
    Inputs can be Python lists, NumPy arrays, or torch Tensors.
    Returns a 1-D tensor of length m, or tensor(-1) if dimensions mismatch.
    """
    a_t = torch.as_tensor(a, dtype=torch.float)
    b_t = torch.as_tensor(b, dtype=torch.float)
    # Dimension mismatch check
    if a_t.size(1) != b_t.size(0):
        return torch.tensor(-1)
    # Your implementation here
    return torch.mv(a_t, b_t)


if __name__ == "__main__":
    a = [[1, 2, 3], [4, 5, 6]]  # a.shape[0] = 2, a.shape[1] = 3
    b = [7, 8, 9]
    ans = matrix_dot_vector_torch(a, b)

    print(ans)
