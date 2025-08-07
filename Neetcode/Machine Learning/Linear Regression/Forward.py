import numpy as np
from numpy.typing import NDArray


# Helpful functions:
# https://numpy.org/doc/stable/reference/generated/numpy.matmul.html
# https://numpy.org/doc/stable/reference/generated/numpy.mean.html
# https://numpy.org/doc/stable/reference/generated/numpy.square.html


class Solution:
    def get_model_prediction(
        self, X: NDArray[np.float64], weights: NDArray[np.float64]
    ) -> NDArray[np.float64]:
        # X is an Nx3 NumPy array
        # weights is a 3x1 NumPy array
        # HINT: np.matmul() will be useful

        # Linear regression prediction: y = X * weights
        predictions = np.matmul(X, weights)

        return np.round(predictions, 5)

    def get_error(
        self, model_prediction: NDArray[np.float64], ground_truth: NDArray[np.float64]
    ) -> float:
        # model_prediction is an Nx1 NumPy array
        # ground_truth is an Nx1 NumPy array
        # HINT: np.mean(), np.square() will be useful

        # Calculate Mean Squared Error (MSE)
        # MSE = mean((prediction - ground_truth)^2)
        squared_errors = np.square(model_prediction - ground_truth)
        mse = np.mean(squared_errors)

        return round(mse, 5)


# Test case
if __name__ == "__main__":
    solution = Solution()

    # Example test case
    # X represents features: [feature1, feature2, feature3] for each data point
    X = np.array(
        [
            [1.0, 2.0, 3.0],  # data point 1
            [4.0, 5.0, 6.0],  # data point 2
            [7.0, 8.0, 9.0],  # data point 3
            [2.0, 1.0, 4.0],  # data point 4
        ]
    )

    # Weights for the linear model: w1, w2, w3
    weights = np.array([0.5, 1.5, 2.0])

    # Ground truth values (correct answers)
    ground_truth = np.array([10.0, 25.0, 40.0, 12.0])

    print("Test Case:")
    print(f"X (input features):\n{X}")
    print(f"Weights: {weights}")
    print(f"Ground truth: {ground_truth}")
    print()

    # Get model predictions
    predictions = solution.get_model_prediction(X, weights)
    print(f"Model predictions: {predictions}")

    # Calculate prediction breakdown for first example:
    # X[0] = [1.0, 2.0, 3.0], weights = [0.5, 1.5, 2.0]
    # prediction = 1.0*0.5 + 2.0*1.5 + 3.0*2.0 = 0.5 + 3.0 + 6.0 = 9.5
    print(
        f"First prediction breakdown: 1.0*0.5 + 2.0*1.5 + 3.0*2.0 = {1.0 * 0.5 + 2.0 * 1.5 + 3.0 * 2.0}"
    )
    print()

    # Calculate error
    error = solution.get_error(predictions, ground_truth)
    print(f"Mean Squared Error: {error}")

    # Error calculation breakdown:
    # errors = [9.5-10.0, 23.5-25.0, 37.5-40.0, 11.0-12.0] = [-0.5, -1.5, -2.5, -1.0]
    # squared_errors = [0.25, 2.25, 6.25, 1.0]
    # mse = (0.25 + 2.25 + 6.25 + 1.0) / 4 = 9.75 / 4 = 2.4375
    errors = predictions - ground_truth
    squared_errors = np.square(errors)
    print(f"Individual errors: {errors}")
    print(f"Squared errors: {squared_errors}")
    print(
        f"MSE calculation: {np.sum(squared_errors)} / {len(squared_errors)} = {np.sum(squared_errors) / len(squared_errors)}"
    )
