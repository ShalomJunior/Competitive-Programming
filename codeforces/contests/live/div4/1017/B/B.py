import sys

input = sys.stdin.readline


def solve():
    n, m, l, r = map(int, input().split())
    L = 0
    R = min(m, r)
    if r < m:
        L = -(m - r)
    print(L, R)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
