# Linear Regression (Forward)
Your task is to implement linear regression, a statistical model that ends up being the foundation of neural networks. 

Your must implement `get_model_prediction()` which returns a prediction value for each dataset value, and `get_error(`) which calculates the error for given prediction data.

Inputs - `get_model_prediction`:

- `X` - the dataset to be used by the model to predict the output. `len(X) = n`, and `len(X[i]) = 3` for `0 <= i < n`.
- weights - the current $w_1$, $w_2$ weights for the model. `len(weights) = 3`.

Inputs - `get_error`:

- `model_prediction` - the model's prediction for each training example. `len(model_prediction) = n`.
- `ground_truth` - the correct answer for each example. `len(ground_truth) = n`.
