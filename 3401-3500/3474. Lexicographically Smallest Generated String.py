class Solution:
    def generateString(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)
        L = n + m - 1

        word = ['?'] * L
        locked = [False] * L

        # Step 1: Apply 'T'
        for i in range(n):
            if str1[i] == 'T':
                for j in range(m):
                    if word[i + j] == '?' or word[i + j] == str2[j]:
                        word[i + j] = str2[j]
                        locked[i + j] = True
                    else:
                        return ""

        # Step 2: Fill with 'a'
        for i in range(L):
            if word[i] == '?':
                word[i] = 'a'

        # Step 3: Fix 'F'
        for i in range(n):
            if str1[i] == 'F':
                match = True

                for j in range(m):
                    if word[i + j] != str2[j]:
                        match = False
                        break

                if match:
                    fixed = False

                    for j in range(m - 1, -1, -1):
                        idx = i + j

                        if locked[idx]:
                            continue

                        for c in range(26):
                            ch = chr(ord('a') + c)
                            if ch != str2[j]:
                                word[idx] = ch
                                fixed = True
                                break

                        if fixed:
                            break

                    if not fixed:
                        return ""

        return "".join(word)
