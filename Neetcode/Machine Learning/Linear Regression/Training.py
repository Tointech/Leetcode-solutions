import numpy as np
from numpy.typing import NDArray


class Solution:
    def get_derivative(
        self,
        model_prediction: NDArray[np.float64],
        ground_truth: NDArray[np.float64],
        N: int,
        X: NDArray[np.float64],
        desired_weight: int,
    ) -> float:
        # note that N is just len(X)
        return -2 * np.dot(ground_truth - model_prediction, X[:, desired_weight]) / N

    def get_model_prediction(
        self, X: NDArray[np.float64], weights: NDArray[np.float64]
    ) -> NDArray[np.float64]:
        return np.squeeze(np.matmul(X, weights))

    learning_rate = 0.01

    def train_model(
        self,
        X: NDArray[np.float64],
        Y: NDArray[np.float64],
        num_iterations: int,
        initial_weights: NDArray[np.float64],
    ) -> NDArray[np.float64]:
        # you will need to call get_derivative() for each weight
        # and update each one separately based on the learning rate!
        # return np.round(your_answer, 5)

        X = np.array(X, dtype=np.float64)
        Y = np.array(Y, dtype=np.float64)
        weights = np.array(initial_weights, dtype=np.float64)

        N = len(X)

        for _ in range(num_iterations):
            # Get current predictions
            predictions = self.get_model_prediction(X, weights)

            # Update each weight separately
            for j in range(len(weights)):
                grad = self.get_derivative(predictions, Y, N, X, j)
                weights[j] -= self.learning_rate * grad

        return np.round(weights, 5)


if __name__ == "__main__":
    sol = Solution()

    X = [[1, 2, 3], [1, 1, 1]]
    Y = [6, 3]
    num_iterations = 10
    initial_weights = [0.2, 0.1, 0.6]

    result = sol.train_model(X, Y, num_iterations, initial_weights)
    print(result)
