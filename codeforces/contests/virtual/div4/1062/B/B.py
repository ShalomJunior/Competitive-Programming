import sys

input = sys.stdin.readline


def solve():
    n = int(input().strip())
    a, b = map(str, input().split())
    print("YES" if sorted(a) == sorted(b) else "NO")


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
