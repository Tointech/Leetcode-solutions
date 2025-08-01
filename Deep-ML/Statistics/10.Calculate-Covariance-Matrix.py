import numpy as np
import torch


# TODO: Numpy version
def calculate_covariance_matrix_numpy(vectors: list[list[float]]) -> list[list[float]]:
    # Your code here
    vectors = np.array(vectors)
    return np.cov(vectors).tolist()


# TODO: Torch version
def calculate_covariance_matrix_torch(vectors) -> torch.Tensor:
    """
    Calculate the covariance matrix for given feature vectors using PyTorch.
    Input: 2D array-like of shape (n_features, n_observations).
    Returns a tensor of shape (n_features, n_features).
    """
    v_t = torch.as_tensor(vectors, dtype=torch.float)
    # Your implementation here
    return torch.cov(v_t)


if __name__ == "__main__":
    # Example usage
    vectors = [[1, 2, 3], [4, 5, 6]]

    result = calculate_covariance_matrix_torch(vectors)
    print(result)
