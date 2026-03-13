# Problem set in Loss Functions

## [Logistic Regression Training Loop](https://www.tensortonic.com/problems/logistic-regression-training) - Medium - [Solution](./1.Logistic-Regression-Training-Loop.py)



## [Implement Cross-Entropy Loss](https://www.tensortonic.com/problems/cross-entropy-loss) - Medium - [Solution](./Loss-Functions/3.Implement-Cross-Entropy-Loss.py)
Compute the average cross-entropy loss for multi-class classification.

`y_true` contains the correct class labels (like [0, 2, 1])

`y_pred` contains the predicted probabilities for each class (each row sums to ~1)

$$
\text{CrossEntropy} = -\frac{1}{N}\sum^N_{i=1}\log(p_{i,y_i})
$$
where $y_i$ = correct class label for sample $i$; $p_{i,y_i}$ = predicted probability for that class
