import numpy as np

def pad_sequences(seqs, pad_value=0, max_len=None):
    """
    Returns: np.ndarray of shape (N, L) where:
      N = len(seqs)
      L = max_len if provided else max(len(seq) for seq in seqs) or 0
    """
    # Your code here
    if max_len is None:
        max_len = max(len(seq) for seq in seqs) if seqs else 0
    

    padded_seqs = np.array([np.pad(seq[:max_len], (0, max(0, max_len - len(seq))), constant_values=pad_value) for seq in seqs])
    return padded_seqs

if __name__ == "__main__":
    seqs = [[1, 2, 3], [4, 5], [6]]
    print(pad_sequences(seqs, pad_value=0))
    print(pad_sequences(seqs, pad_value=-1, max_len=5))