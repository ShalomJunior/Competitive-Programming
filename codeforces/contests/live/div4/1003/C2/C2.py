import sys
from bisect import bisect_left

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    s = sorted(list(set(b)))
    a[0] = min(a[0], min(s) - a[0])
    for i in range(1, n):
        x = a[i]
        it = bisect_left(s, a[i] + a[i - 1])
        if it < len(s):
            y = s[it] - a[i]
            if x > y:
                x, y = y, x
            if a[i - 1] <= x:
                a[i] = x
            else:
                a[i] = y
    print("YES" if a == sorted(a) else "NO")


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
