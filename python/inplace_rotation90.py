import numpy as np


def inplace_rotation90(mat):
    n = mat.shape[0]
    if n != mat.shape[1]:
	    raise ValueError("input should be square")
    for i in range(n-1):
       for j in range(i, n-i-1):
          a0 = mat[j, n-i-1]
          mat[j, n-i-1] = mat[i, j]
          a1 = mat[n-i-1, n-j-1]
	  mat[n-i-1, n-j-1] = a0
          a0 = mat[n-j-1, i]
          mat[n-j-1, i] = a1
          mat[i, j] = a0
    return mat


if __name__ =='__main__':
   n = 5
   x = np.array(range(n*n), dtype=np.int32).reshape((n, n))
   print(x)
   print()
   print(inplace_rotation90(x))
