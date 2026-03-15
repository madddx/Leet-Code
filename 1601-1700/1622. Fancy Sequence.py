class Fancy:

    def __init__(self):
        self.a = []
        self.i = 0
        self.m = 1
        self.mod = 10**9+7
        
    def append(self, val: int) -> None:
        self.a.append([val, self.m, self.i])

    def addAll(self, inc: int) -> None:
        self.i += inc

    def multAll(self, m: int) -> None:
        # if current is self.a[x] = v, mul, inc
        # number will be v*mul + inc
        # now I am multiplying this number by m
        # (v*mul+inc)*m = v*mul*m +inc*m --> both existing mul and inc got multiplied by m
        self.m = self.m * m % self.mod
        self.i = self.i * m % self.mod

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.a):
            return -1
        v, vm, vi = self.a[idx]
        # self.m is cumulative multiplication
        # vm is multiplication before that point
        # we undo the transformation that was done before.
        # ratio = self.m // vm ---> the transformation that was done before
        # multiply is simple to handle, but remember the above step
        # we even added it to the increment. So need to subtract all
        # contribution the multipliers did to the increments before as well.
        # this means the transformation for index included a part of the multiplier and the increment
        # this can be calculated directly using math (subtract the prev added and multiply the future results)
        # for this we need that ratio = self.m // vm
        # this needs to be done using modular inversion
        ratio = self.m * pow(vm, self.mod-2, self.mod)
        return (v * ratio + self.i - ratio * vi) % self.mod
        


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)
