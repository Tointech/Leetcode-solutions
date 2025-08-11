# Linear Regression (Forward)
Your task is to implement linear regression, a statistical model that ends up being the foundation of neural networks. 

Your must implement `get_model_prediction()` which returns a prediction value for each dataset value, and `get_error(`) which calculates the error for given prediction data.

Inputs - `get_model_prediction`:

- `X` - the dataset to be used by the model to predict the output. `len(X) = n`, and `len(X[i]) = 3` for `0 <= i < n`.
- weights - the current $w_1$, $w_2$ weights for the model. `len(weights) = 3`.

Inputs - `get_error`:

- `model_prediction` - the model's prediction for each training example. `len(model_prediction) = n`.
- `ground_truth` - the correct answer for each example. `len(ground_truth) = n`.

# Linear Regression (Training)

Now that you've implemented `get_model_prediction()` for a model, it's time to implement the training loop. At every iteration of the training loop, the previous function as well as `get_derivative()` should be called in order to perform gradient descent.

Your goal is to implement the `train_model()` function, which has the following as input:

1. `X`: The dataset for training the model. `X.length = n` and `X[i].length = 3` for `0 <= i < n`.
2. `Y`: The correct answers from the dataset. `Y.length = n`.
3. `num_iterations`: The number of iterations to run gradient descent for. `num_iterations > 0`.
4. `initial_weights`: The initial weights for the model $(w_1, w_2, w_3)$. `initial_weights.length = 3`.

Return the final weights after training in the form of a NumPy array with dimension 3.

Example 1:

```python
Input:
X = [[1, 2, 3], [1, 1, 1]]
Y = [6, 3]
num_iterations = 10
initial_weights = [0.2, 0.1, 0.6]

Output:
[0.50678, 0.59057, 1.27435]
```

Note: The `get_derivative()` function is provided for you since it's rare for machine learning engineers or data scientists to calculate them by hand. In future problems, you will use a library like PyTorch to calculate the derivatives for you.
