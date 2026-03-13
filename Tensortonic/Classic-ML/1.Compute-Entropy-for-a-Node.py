import numpy as np

def entropy_node(y):
    """
    Compute entropy for a single node using stable logarithms.
    """
    # Write code here
    y = np.array(y)
    
    # Count the occurrences of each class
    classes, counts = np.unique(y, return_counts=True)
    
    # Calculate probabilities
    probabilities = counts / counts.sum()
     
    # Compute entropy using stable logarithms
    entropy = -np.sum(probabilities * np.log2(probabilities))
    
    return entropy