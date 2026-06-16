class Solution:

    def processStr(self, s: str) -> str:
        result = []

        for c in s:
            if c.islower():
                result.append(c)
            elif c == '*':
                if result:
                    result.pop()
            elif c == '#':
                # Production note, this was the fastest way to do the doubling of the string
                result += result 

                # Production note: Using the built-in .reverse() method
                # is the most efficient 'best practice' way to perform
                # an in-place reversal in Python.
            elif c == '%':
                result.reverse()
        
        return "".join(result)
