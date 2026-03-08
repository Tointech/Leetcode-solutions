import numpy as np

def sigmoid(x):
    """
    Vectorized sigmoid function.
    """
    # Write code here
    x = np.array(x, dtype=float)
    return 1/(1 + np.exp(-x))

if __name__ == "__main__":
    # Test the function
    x = np.array([-1, 0, 1])
    print(sigmoid(x))