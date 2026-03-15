# Problem set in Activation Functions

## [Implement Sigmoid in Numpy](https://www.tensortonic.com/problems/sigmoid-numpy) - Easy - [Solution](./1.Implement-Sigmoid-in-Numpy.py)

$$
\sigma(x)=\frac{1}{1+e^{-x}} \to (0, 1)
$$


## [Implement Tanh Activation](https://www.tensortonic.com/problems/tanh-activation) - Easy - [Solution](./2.Implement-Tanh-Activation.py)

$$
\tanh(x)=\frac{e^x-e^{-x}}{e^x+e^{-x}} \to (-1, 1)
$$

Tanh values symmetric around zero.

## [Implement Softmax Function](https://www.tensortonic.com/problems/softmax-function) - Easy - [Solution](./9.Implement-Softmax-Function.py)

To convert numerical scores (logits) into probabilities, the key requirement is:
- Values must be non-negative $\to$ exponential
- They must sum to 1 $\to$ normalize 

For a vector $x=[x_1, x_2, \dots, x_n]$:
$$
\text{softmax}(x_i) = \frac{e^{x_i}}{\sum_j e^{x_j}}
$$

In practice, to avoid numerical overflow, the stable version subtracts the maximum value: 
$$
\text{softmax} = \frac{e^{x_i - \text{max}(x)}}{\sum_j e^{x_j - \text{max}(x)}}
$$

## [Implement ReLU Function](https://www.tensortonic.com/problems/relu-activation) - Easy - [Solution](./4.Implement-ReLU-Activation.py)

$$
\text{ReLU}(x) = max(0, x)
$$

## [Implement Leaky ReLU (with a)](https://www.tensortonic.com/problems/leaky-relu) - Easy - [Solution](./7.Implement-Leaky-ReLU-(with-a).py)

Standard ReLU outputs 0 for negative inputs, which can cause "dead neurons".

By introducing a small leak value  α, Leaky ReLU allows a small gradient to flow for negative inputs, helping prevent the dying ReLU problem and keeping learning active.

$$
f(x) =
\begin{cases}
x & \text{if } x \ge 0 \\
ax & \text{if } x < 0
\end{cases}
$$