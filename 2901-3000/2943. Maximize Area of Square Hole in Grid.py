class Solution(object):
    def maximizeSquareHoleArea(self, n, m, hBars, vBars):
        """
        :type n: int
        :type m: int
        :type hBars: List[int]
        :type vBars: List[int]
        :rtype: int
        """
        hBars.sort()
        vBars.sort()
        hdiff=0
        vdiff=0
        count=0
        i=0
        j=0
        while i<(len(hBars)-1): 
            if hBars[i]+1==hBars[i+1]:
                count+=1
                i+=1
            else:
                hdiff=max(hdiff,count)
                count=0
                i+=1
        hdiff=max(hdiff,count)
        count=0
        while j<(len(vBars)-1): 
            if vBars[j]+1==vBars[j+1]:
                count+=1
                j+=1
            else:
                vdiff=max(vdiff,count)
                count=0
                j+=1
        vdiff=max(vdiff,count)
        
        x=min(vdiff,hdiff)

        return (x+2)**2
            

        
