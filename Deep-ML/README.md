# Problem set in [Deep-ML](https://www.deep-ml.com/problems)
## Notebooks
### 1. Linear Algebra
#### 1.1 Matrix-Vector Dot Product
Numpy Version
```python
a = np.array(a)
b = np.array(b)

if a.shape[1] != b.shape[0]:
    return -1

return np.dot(a, b).tolist()
```

Torch version
```python
a_t = torch.as_tensor(a, dtype=torch.float)
b_t = torch.as_tensor(b, dtype=torch.float)

if a_t.size(1) != b_t.size(0):
    return torch.tensor(-1)

return torch.mv(a_t, b_t)
```