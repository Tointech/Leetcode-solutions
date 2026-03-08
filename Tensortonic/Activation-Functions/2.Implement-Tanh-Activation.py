import numpy as np

def tanh(x):
    """
    Implement Tanh activation function.
    """
    # Write code here
    x = np.array(x, dtype=float)
    return (np.exp(x)-np.exp(-x))/(np.exp(x)+np.exp(-x))

if __name__ == "__main__":
    # Test the function
    x = np.array([-2, -1, 0, 1, 2])
    print("Input:", x)
    print("Tanh Output:", tanh(x))