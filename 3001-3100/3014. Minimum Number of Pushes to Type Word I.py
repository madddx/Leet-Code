class Solution:
    def minimumPushes(self, word: str) -> int:
        return ((n:=len(word))%8)*((q:=(n>>3))+1)+q*(q+1)*4
