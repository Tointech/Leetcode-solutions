# Problem set in Classic ML

## [Compute Entropy for a Node](https://www.tensortonic.com/problems/entropy-node) - Easy - [Solution](./1.Compute-Entropy-for-a-Node.py)

Entropy measures the amount of uncertainty or randomness in a dataset. In decision trees, it's used as a spliting criterion to build trees that maximize information gain.

$$
H(S) = -\sum_{i=1}^{C}p_i \log_2(p_i)
$$

where $p_i$ is the proportion of samples belonging to class i, and C is the number of classes. By convention, $0 \log_2(p_i)=0$.
