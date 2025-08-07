class Solution:
    def get_minimizer(self, iterations: int, learning_rate: float, init: int) -> float:
        # Initilaize x with initial guess
        x = init

        for i in range(iterations):
            # f(x) = x^2 -> f'(x) = 2x
            gradient = 2 * x

            # Update x: x_new = x_old - learning_rate * gradient
            x = x - learning_rate * gradient

        return round(x, 5)


if __name__ == "__main__":
    sol = Solution()

    result = sol.get_minimizer(iterations=0, learning_rate=0.01, init=5)
    print(result)
