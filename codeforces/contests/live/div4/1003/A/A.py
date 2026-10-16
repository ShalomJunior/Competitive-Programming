import sys

input = sys.stdin.readline


def solve():
    s = input().strip()
    print(s[:-2] + "i")


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
