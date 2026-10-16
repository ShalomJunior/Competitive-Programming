import sys

input = sys.stdin.readline


def solve():
    a, b = map(int, input().split())
    ans = 10**9
    for c in range(a, b + 1):
        ans = min(ans, c - a + b - c)
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
