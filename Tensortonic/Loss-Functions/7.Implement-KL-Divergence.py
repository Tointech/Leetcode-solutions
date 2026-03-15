import numpy as np

def kl_divergence(p, q, eps=1e-12):
    """
    Compute KL Divergence D_KL(P || Q).
    """
    # Write code here
    p = np.asarray(p, dtype=np.float32) + eps
    q = np.asarray(q, dtype=np.float32) + eps
    
    kl_div = np.sum(p * np.log(p / q))
    return kl_div

if __name__ == "__main__":
    p = [0.1, 0.5, 0.4]
    q = [0.2, 0.3, 0.5]
    
    kl_result = kl_divergence(p, q)
    print(f"KL Divergence D_KL(P || Q): {kl_result}")