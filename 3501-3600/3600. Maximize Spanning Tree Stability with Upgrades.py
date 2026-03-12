class Solution:
    def maxStability(self, n: int, edges: list[list[int]], k: int) -> int:
        parent = list(range(n))

        def find(i):
            while i != parent[i]:
                parent[i] = parent[parent[i]]
                i = parent[i]
            return i

        min_m = float('inf')
        comp_count = n

        for u, v, w, must in edges:
            if must == 1:
                ru = find(u)
                rv = find(v)
                if ru == rv:
                    return -1
                parent[ru] = rv
                comp_count -= 1
                if w < min_m:
                    min_m = w

        opt = []
        for u, v, w, must in edges:
            if must == 0:
                ru = find(u)
                rv = find(v)
                if ru != rv:
                    # Packing: weight (30 bits) | ru (17 bits) | rv (17 bits)
                    opt.append((w << 34) | (ru << 17) | rv)

        if comp_count == 1:
            return int(min_m)

        # Radix Sort
        if len(opt) > 1:
            temp = [0] * len(opt)
            for shift in range(34, 64, 8):
                count = [0] * 256
                for val in opt:
                    count[(val >> shift) & 0xFF] += 1
                for i in range(1, 256):
                    count[i] += count[i - 1]
                for i in range(len(opt) - 1, -1, -1):
                    val = opt[i]
                    idx = (val >> shift) & 0xFF
                    count[idx] -= 1
                    temp[count[idx]] = val
                opt, temp = temp, opt

        upg = []
        for i in range(len(opt) - 1, -1, -1):
            packed = opt[i]
            ru = find((packed >> 17) & 0x1FFFF)
            rv = find(packed & 0x1FFFF)
            
            if ru != rv:
                parent[ru] = rv
                upg.append(packed >> 34)
                comp_count -= 1
                if comp_count == 1:
                    break

        if comp_count > 1:
            return -1

        for i in range(len(upg) - 1, -1, -1):
            if k > 0:
                k -= 1
                upgraded = upg[i] << 1
                if upgraded < min_m:
                    min_m = upgraded
            else:
                if upg[i] < min_m:
                    min_m = upg[i]
                break

        return int(min_m)
