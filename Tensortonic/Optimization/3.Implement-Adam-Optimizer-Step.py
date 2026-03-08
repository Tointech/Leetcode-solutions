import numpy as np

def adam_step(param, grad, m, v, t, lr=1e-3, beta1=0.9, beta2=0.999, eps=1e-8):
    """
    One Adam optimizer update step.
    Return (param_new, m_new, v_new).
    """
    # Write code here
    param = np.array(param, dtype=float)
    grad = np.array(grad, dtype=float)
    m = np.array(m, dtype=float)
    v = np.array(v, dtype=float)

    # Update biased first moment estimate
    m_new = beta1 * m + (1 - beta1) * grad 
    v_new = beta2 * v + (1 - beta2) * (grad ** 2)
    
    # Compute bias-corrected first and second moment estimates
    m_hat = m_new / (1 - beta1 ** t)
    v_hat = v_new / (1 - beta2 ** t)
    
    # Update parameters
    param_new = param - lr * m_hat / (np.sqrt(v_hat) + eps)
    
    return param_new, m_new, v_new

if __name__ == "__main__":
    # Example usage
    param = 0.5
    grad = 0.1
    m = 0.0
    v = 0.0
    t = 1
    
    param_new, m_new, v_new = adam_step(param, grad, m, v, t)
    print(f"Updated parameter: {param_new}, m: {m_new}, v: {v_new}")