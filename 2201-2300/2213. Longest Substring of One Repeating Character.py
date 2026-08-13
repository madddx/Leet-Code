class Solution:

    def longestRepeating(self, s, queryCharacters, queryIndices):

        n = len(s)

        # Each node:
        # [length, prefix, suffix, best, left_char, right_char]
        tree = [None] * (4 * n)

        def merge(a, b):
            length = a[0] + b[0]

            pref = a[1]
            if a[1] == a[0] and a[5] == b[4]:
                pref = a[0] + b[1]

            suff = b[2]
            if b[2] == b[0] and a[5] == b[4]:
                suff = b[0] + a[2]

            best = max(a[3], b[3])

            if a[5] == b[4]:
                best = max(best, a[2] + b[1])

            return [
                length,
                pref,
                suff,
                best,
                a[4],
                b[5]
            ]

        def build(node, l, r):
            if l == r:
                tree[node] = [1, 1, 1, 1, s[l], s[l]]
                return

            mid = (l + r) // 2

            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)

            tree[node] = merge(
                tree[node * 2],
                tree[node * 2 + 1]
            )

        def update(node, l, r, idx, c):
            if l == r:
                tree[node] = [1, 1, 1, 1, c, c]
                return

            mid = (l + r) // 2

            if idx <= mid:
                update(node * 2, l, mid, idx, c)
            else:
                update(node * 2 + 1, mid + 1, r, idx, c)

            tree[node] = merge(
                tree[node * 2],
                tree[node * 2 + 1]
            )

        build(1, 0, n - 1)

        ans = []

        for i in range(len(queryCharacters)):

            idx = queryIndices[i]
            c = queryCharacters[i]

            update(1, 0, n - 1, idx, c)

            ans.append(tree[1][3])

        return ans
