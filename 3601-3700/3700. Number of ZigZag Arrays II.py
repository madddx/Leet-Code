class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        m = r - l + 1

        # Initial vector F2[v] = v-1 (0-indexed => v)
        vec = [[i] for i in range(m)]

        # Build matrix A
        A = [[0] * m for _ in range(m)]
        for v in range(m):
            for k in range(m):
                if (v + 1) + (k + 1) > m + 1:
                    A[v][k] = 1

        def mat_mul(X, Y):
            n1, n2, n3 = len(X), len(Y), len(Y[0])
            res = [[0] * n3 for _ in range(n1)]

            for i in range(n1):
                for k in range(n2):
                    if X[i][k] == 0:
                        continue
                    x = X[i][k]
                    for j in range(n3):
                        res[i][j] = (res[i][j] + x * Y[k][j]) % MOD
            return res

        def mat_pow(M, p):
            size = len(M)

            R = [[0] * size for _ in range(size)]
            for i in range(size):
                R[i][i] = 1

            while p:
                if p & 1:
                    R = mat_mul(R, M)
                M = mat_mul(M, M)
                p >>= 1

            return R

        P = mat_pow(A, n - 2)
        Fn = mat_mul(P, vec)

        return (2 * sum(row[0] for row in Fn)) % MOD
