class Solution:
    def isPossible(self, n, freq, cur, mid, target):
        freq = freq[:]  # copy, since C++ passes freq by value here

        # build the largest possible arrangement of remaining chars (descending order)
        for i in range(25, -1, -1):
            while freq[i]:
                cur += chr(ord('a') + i)
                freq[i] -= 1

        if mid != '#':
            # odd-length palindrome: left half + mid + reverse(left half)
            temp = cur
            cur += mid
            temp = temp[::-1]
            cur += temp
        else:
            # even-length palindrome: left half + reverse(left half)
            temp = cur
            temp = temp[::-1]
            cur += temp

        # feasibility check: only valid if this (largest possible) candidate beats target
        return cur if cur > target else ""

    def lexPalindromicPermutation(self, s, target):
        n = len(s)

        freq = [0] * 26

        if n == 1:
            if s > target:
                return s
            else:
                return ""

        for c in s:
            freq[ord(c) - ord('a')] += 1

        mid = '#'
        oddCount = 0

        for i in range(26):
            if freq[i] % 2:
                # odd count -> this becomes the middle character
                mid = chr(ord('a') + i)
                freq[i] -= 1
                oddCount += 1

            freq[i] //= 2  # each char used freq[i]/2 times in the left half

            if oddCount >= 2:
                return ""  # more than one odd-frequency char -> can't form a palindrome

        n //= 2  # we only need to construct the left half now

        res, prefix = "", ""

        # greedily build the left half, position by position
        for i in range(n):

            cur = prefix
            isThereAny = False

            # try smallest character first ('a' -> 'z')
            for j in range(26):

                if freq[j]:

                    freq[j] -= 1
                    cur += chr(ord('a') + j)

                    # check if this prefix can still lead to a palindrome > target
                    isPos = self.isPossible(n, freq, cur, mid, target)

                    if isPos != "":
                        prefix = cur      # keep this character, lock in the prefix
                        isThereAny = True

                        if res == "":
                            res = isPos
                        else:
                            res = min(res, isPos)  # track smallest valid candidate seen

                        break

                    # this character doesn't work, undo and try the next one
                    freq[j] += 1
                    cur = cur[:-1]

            if not isThereAny:
                return ""  # no character works at this position -> impossible

        return  res 
