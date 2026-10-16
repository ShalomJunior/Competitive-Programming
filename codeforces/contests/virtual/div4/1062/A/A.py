import sys

input = sys.stdin.readline


def solve():
    a, b, c, d = map(int, input().split())
    x = min(a, b, c, d)
    y = max(a, b, c, d)
    print("YES" if x == y else "NO")


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
