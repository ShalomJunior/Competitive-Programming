import sys

input = sys.stdin.readline


def solve():
    s = input().strip()
    n = len(s)
    j = -1
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            j = i

    print(n if j == -1 else 1)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
