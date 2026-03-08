def gradient_descent_quadratic(a, b, c, x0, lr, steps):
    """
    Return final x after 'steps' iterations.
    """
    # Write code here
    x = x0
    
    for i in range(steps):
        # Calculate the gradient of the quadratic function at the current x
        gradient = 2 * a * x + b
        
        # Update x using the gradient descent formula
        x = x - lr * gradient
        
    return x