class Solution:
    def processStr(self, s: str, k: int) -> str:
        L=0
        for c in s:
            match c:
                case '*': L-=(L>0)
                case '#': L<<=1
                case '%': pass
                case _: L+=1
        if L-1<k: return '.'
        for c in reversed(s):
            if L==0: continue
            match c:
                case '*': L+=1
                case '#':
                    L>>=1
                    if k>=L: k-=L
                case '%': k=L-1-k
                case _:
                    if k==L-1: return c
                    L-=1
        return '.'           
        
