import sys

input = sys.stdin.readline


def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    o = sum([a[i] % 2 for i in range(n)])
    e = n - o
    if e > 0 and o > 0:
        a.sort()
    print(*a)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
