class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        count = [0] * 26
        for ch in s:
            count[ord(ch) - ord('a')] += 1

        n = len(s)
        matched = 0

        while matched < n and count[ord(target[matched]) - ord('a')] > 0:
            count[ord(target[matched]) - ord('a')] -= 1
            matched += 1

        start = matched if matched < n else n - 1

        for i in range(start, -1, -1):
            if i < matched:
                count[ord(target[i]) - ord('a')] += 1

            bigger = -1
            for ch in range(ord(target[i]) - ord('a') + 1, 26):
                if count[ch] > 0:
                    bigger = ch
                    break

            if bigger != -1:
                count[bigger] -= 1

                answer = target[:i] + chr(ord('a') + bigger)

                for ch in range(26):
                    answer += chr(ord('a') + ch) * count[ch]

                return answer

        return ""
