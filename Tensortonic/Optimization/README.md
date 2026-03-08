# Problem set in Optimization

## [Logistic Regression Training Loop](https://www.tensortonic.com/problems/logistic-regression-training) - Medium - [Solution](./1.Logistic-Regression-Training-Loop.py)

Train a binary logistic regression classifier using gradient descent. Implement the training loop and return the learned parameters (w, b).

Model: 
$$
p = \sigma(Xw + b) = \frac{1}{1 + e^{-(Xw + b)}}
$$

Loss (Binary Cross-Entropy):
$$
L = -\frac{1}{N} \sum_{i=1}^{N} 
\left[
y_i \log(p_i) + (1 - y_i)\log(1 - p_i)
\right]
$$

## [Implement Gradient Descent for a 1D Quadratic](https://www.tensortonic.com/problems/gradient-descent-quadratic) - Easy - [Solution](./2.Implement-Gradient-Descent-for-a-1D-Quadratic.py)

Implement vanilla gradient descent to minimize a 1-D quadratic:
$$
f(x) = ax^2 + bx + c
$$
