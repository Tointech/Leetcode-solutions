# Gradient Descent 
Your task is to minimize the function via Gradient Descent:$f(x) = x^2$.

Gradient Descent is an optimization technique widely used in machine learning for training models. It is crucial for minimizing the cost or loss function and finding the optimal parameters of a model.

For the above function the minimizer is clearly x = 0, but you must implement an iterative approximation algorithm, through gradient descent.

Input:
- `iterations` - the number of iterations to perform gradient descent. `iterations >= 0`.
- `learning_rate` - the learning rate for gradient descent. 1 > learning_rate > 0.
- `init` - the initial guess for the minimizer. `init != 0`.
- 
Given the number of iterations to perform gradient descent, the learning rate, and an initial guess, return the value of `x` that globally minimizes this function.

Round your final result to 5 decimal places using Python's `round()` function.

![image](./gradient-descent.png)
