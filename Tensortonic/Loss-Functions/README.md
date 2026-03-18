# Problem set in Loss Functions

## [Logistic Regression Training Loop](https://www.tensortonic.com/problems/logistic-regression-training) - Medium - [Solution](./1.Logistic-Regression-Training-Loop.py)

## [Implement Cross-Entropy Loss](https://www.tensortonic.com/problems/cross-entropy-loss) - Medium - [Solution](3.Implement-Cross-Entropy-Loss.py)

Compute the average cross-entropy loss for multi-class classification.

`y_true` contains the correct class labels (like [0, 2, 1])

`y_pred` contains the predicted probabilities for each class (each row sums to ~1)

$$
\text{CrossEntropy} = -\frac{1}{N}\sum^N_{i=1}\log(p_{i,y_i})
$$
where $y_i$ = correct class label for sample $i$; $p_{i,y_i}$ = predicted probability for that class

## [Implement KL Divergence](https://www.tensortonic.com/problems/kl-divergence) - Medium - [Solution](./7.Implement-KL-Divergence.py)

KL Divergence (Kullback-Leibler divergence) to measure how one probability distribution differs from another.
$$
D_{KL}(P||Q) =\sum_i P_i \log \frac{P_i}{Q_i}
$$
where P and Q are probability distributions

## [Mean Squared Error (MSE)](https://www.tensortonic.com/problems/mean-squared-error) - Easy - [Solution](./9.Mean-Squared-Error(MSE).py)
Compute the Mean Squared Error between predictions and targets.
$$
\text{MSE} = \frac{1}{N} \sum_{i=0}^{N-1}(y_{\text{pred}}[i]-y_{\text{true}}[i])^2
$$
where N is the number of samples.

## [Cosine Embedding Loss](https://www.tensortonic.com/problems/cosine-embedding-loss) - Easy - [Solution](./10.Cosine-Embedding-Loss.py)
Cosine embedding loss measures whether two vectors are similar or dissimilar based on a label. It is commonly used in metric learning and siamese networks to learn embeddings where similar items are close and dissimilar items are far apart in cosine space.

Given two vectors, a label (+1 for similar, -1 for dissimilar), and a margin, compute the cosine embedding loss.

First compute the cosine similarity:
$$
\cos(x_1, x_2) = \frac{x_1 \cdot x_2}{\| x_1 \| \cdot \| x_2 \|}
$$
Then compute the loss based on the label:
$$
L = 1 - \cos(x_1, x_2) \quad \text{if label = 1}
$$
$$
L = \max(0, \cos(x_1, x_2) - \text{margin}) \quad \text{if label = -1}
$$