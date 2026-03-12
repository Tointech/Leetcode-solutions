import numpy as np

def softmax(x):
    """
    Compute the softmax of input x.
    Works for 1D or 2D NumPy arrays.
    For 2D, compute row-wise softmax.
    """
    # Write code here
    x = np.array(x)
    
    if x.ndim == 1:
        # For 1D array, compute softmax directly
        exp_x = np.exp(x - np.max(x))  # Subtract max for numerical stability
        return exp_x / np.sum(exp_x)
    elif x.ndim == 2:
        # For 2D array, compute softmax row-wise
        exp_x = np.exp(x - np.max(x, axis=1, keepdims=True))  # Subtract max for numerical stability
        return exp_x / np.sum(exp_x, axis=1, keepdims=True)
    else:
        raise ValueError("Input must be a 1D or 2D array.") 
    