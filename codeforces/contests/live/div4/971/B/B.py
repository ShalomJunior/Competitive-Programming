import sys

input = sys.stdin.readline
N = 4


def solve():
    n = int(input().strip())
    a = [input() for _ in range(n)]
    for i in range(n - 1, -1, -1):
        s = a[i]
        for j in range(N):
            if s[j] == "#":
                print(j + 1, end=" ")
    print()


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
