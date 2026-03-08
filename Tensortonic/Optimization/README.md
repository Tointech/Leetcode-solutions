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

## [Implement Adam Optimizer Step](./3.Implement-Adam-Optimizer-Step.py) - Easy - [Solution](./3.Implement-Adam-Optimizer-Step.py)

Implement one update step of the Adam optimizer. Given current parameter(s), gradient(s), and running first/second moments, return the updated parameter(s) and updated moments.

### Update equations
#### First Moment Estimate (Momentum)
$$
m_t = \beta_1 \cdot m_{t-1} + (1 - \beta_1) \cdot g_t
$$

#### Second Moment Estimate (RMSProp-like)
$$
v_t = \beta_2 \cdot v_{t-1} + (1 - \beta_2) \cdot g_t^2
$$

#### Bias-Corrected First Moment
$$
\hat{m}_t = \frac{m_t}{1 - \beta_1^t}
$$

#### Bias-Corrected Second Moment
$$
\hat{v}_t = \frac{v_t}{1 - \beta_2^t}
$$

#### Parameter Update

$$
\theta_t = \theta_{t-1} - \alpha \cdot 
\frac{\hat{m}_t}{\sqrt{\hat{v}_t} + \epsilon}
$$
