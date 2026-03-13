import numpy as np

def cross_entropy_loss(y_true, y_pred):
    """
    Compute average cross-entropy loss for multi-class classification.
    """
    # Write code here
    y_true = np.array(y_true)
    y_pred = np.array(y_pred)
    
    loss = -np.log(y_pred[np.arange(len(y_true)), y_true]).mean()
    return loss


if __name__ == "__main__":
    # Example usage
    y_true = [1, 0, 1]
    y_pred = [
        [0.2, 0.8],
        [0.6, 0.4],
        [0.49, 0.51]
    ]
    
    loss = cross_entropy_loss(y_true, y_pred)
    print(f"Cross-Entropy Loss: {loss:.4f}")