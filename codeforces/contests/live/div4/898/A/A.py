import sys

input = sys.stdin.readline


def solve():
    s = input().strip()
    print("NO" if s == "bca" or s == "cab" else "YES")


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
