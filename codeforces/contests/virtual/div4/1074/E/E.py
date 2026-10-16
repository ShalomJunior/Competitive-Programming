import sys
from bisect import bisect_left, bisect_right

input = sys.stdin.readline
INF = 10**18


def solve():
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    b.sort()
    s = input().strip()
    L = []
    R = []
    for i in range(n):
        idx = bisect_left(b, a[i])
        if idx > 0:
            L.append((a[i] - b[idx - 1], i))
        else:
            L.append((INF, i))

        idx = bisect_right(b, a[i])
        if idx < m:
            R.append((b[idx] - a[i], i))
        else:
            R.append((INF, i))

    L.sort(reverse=True)
    R.sort(reverse=True)
    j = 0
    out = set()
    ans = []
    for c in s:
        if c == "L":
            j -= 1
        else:
            j += 1
        if j < 0:
            while L and L[-1][0] <= -j:
                out.add(L[-1][1])
                L.pop()
        elif j > 0:
            while R and R[-1][0] <= j:
                out.add(R[-1][1])
                R.pop()

        ans.append(n - len(out))

    print(*ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
