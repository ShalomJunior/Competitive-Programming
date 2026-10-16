import sys
from bisect import bisect_right

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    h = list(map(int, input().split()))

    seg = []
    start = 0
    for i in range(1, n):
        if h[i - 1] % h[i] > 0:
            seg.append((start, i - 1))
            start = i
            if i == n - 1:
                seg.append((n - 1, n - 1))
            continue
        if i == n - 1:
            seg.append((start, i))
    if n == 1:
        seg.append((0, 0))

    pref = [0] * n
    for i in range(n):
        pref[i] = a[i] + (pref[i - 1] if i > 0 else 0)
    ans = 0
    for l, r in seg:
        for i in range(l, r + 1):
            it = bisect_right(pref, k + (pref[i - 1] if i > 0 else 0))
            it -= 1
            j = min(it, r)
            ans = max(ans, j - i + 1)
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
