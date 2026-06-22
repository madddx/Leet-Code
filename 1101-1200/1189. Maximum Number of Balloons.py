class Solution:
    def maxNumberOfBalloons(self, text):
        text = list(text)
        ans = 0

        while True:
            word = list("balloon")

            for c in word:
                found = False

                for i in range(len(text)):
                    if text[i] == c:
                        text[i] = '#'
                        found = True
                        break

                if not found:
                    return ans

            ans += 1
