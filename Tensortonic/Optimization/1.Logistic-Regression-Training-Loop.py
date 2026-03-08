import numpy as np

def _sigmoid(z):
    """Numerically stable sigmoid implementation."""
    return np.where(z >= 0, 1/(1+np.exp(-z)), np.exp(z)/(1+np.exp(z)))

def train_logistic_regression(X, y, lr=0.1, steps=1000):
    """
    Train logistic regression via gradient descent.
    Return (w, b).
    """
    n_samples, n_features = X.shape
    
    # Initialize parameters
    w = np.zeros(n_features)
    b = 0
    
    for step in range(steps):
        
        # Linear model
        z = X @ w + b
        
        # Apply sigmoid
        model = _sigmoid(z)
        
        # Compute gradients
        dw = (1/n_samples) * (X.T @ (model - y))
        db = (1/n_samples) * np.sum(model - y)
        
        # Update parameters
        w -= lr * dw
        b -= lr * db
        
    return w, b


if __name__ == "__main__":
    
    # Sample data (OR gate)
    X = np.array([[0,0],
                  [0,1],
                  [1,0],
                  [1,1]])
    
    y = np.array([0,1,1,1])
    
    w, b = train_logistic_regression(X, y)
    
    print("Weights:", w)
    print("Bias:", b)