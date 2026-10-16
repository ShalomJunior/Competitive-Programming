import sys
from bisect import bisect_left
from collections import defaultdict

input = sys.stdin.readline

_divs_cache = {}


def divs(n):
    if n in _divs_cache:
        return _divs_cache[n]
    d = []
    i = 1
    while i * i <= n:
        if n % i == 0:
            d.append(i)
            if i * i < n:
                d.append(n // i)

        i += 1
    _divs_cache[n] = d
    return d


def solve():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    h = {}
    for i in range(n):
        val = a[i]
        if val in h:
            h[val].append(i)
        else:
            h[val] = [i]

    for _ in range(q):
        k, l, r = map(int, input().split())
        l -= 1
        r -= 1
        pos = []
        for d in divs(k):
            if d in h:
                v = h[d]
                idx = bisect_left(v, l)
                if idx < len(v) and v[idx] <= r:
                    pos.append(v[idx])
        pos.sort()
        j = l
        ans = 0
        for id in pos:
            cnt = id - j
            ans += cnt * k
            while k % a[id] == 0:
                k //= a[id]
            j = id
        ans += (r + 1 - j) * k
        print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
