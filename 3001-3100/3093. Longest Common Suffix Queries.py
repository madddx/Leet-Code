class Node:
    def __init__(self):
        self.child = [-1] * 26
        self.idx = -1

class Solution:
    # update best index according to:
    # 1. smaller length
    # 2. earlier index
    def updateIndex(self,storedIdx,newIdx,wordsContainer):
        if storedIdx == -1:
            return newIdx

        oldLen = len(wordsContainer[storedIdx])
        newLen = len(wordsContainer[newIdx])

        if newLen < oldLen:
            return newIdx

        if newLen == oldLen and newIdx < storedIdx:
            return newIdx

        return storedIdx

    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        trie = [Node()]  # root node

        # build reverse trie
        for i in range(len(wordsContainer)):
            word = wordsContainer[i][::-1]

            node = 0

            # update root answer
            trie[node].idx = self.updateIndex(trie[node].idx,i,wordsContainer)

            for ch in word:
                c = ord(ch) - ord('a')

                if trie[node].child[c] == -1:
                    trie[node].child[c] = len(trie)
                    trie.append(Node())

                node = trie[node].child[c]

                trie[node].idx = self.updateIndex(trie[node].idx,i,wordsContainer)

        ans = []

        # process queries
        for query in wordsQuery:
            query = query[::-1]

            node = 0

            for ch in query:
                c = ord(ch) - ord('a')

                if trie[node].child[c] == -1:
                    break

                node = trie[node].child[c]

            ans.append(trie[node].idx)

        return ans
