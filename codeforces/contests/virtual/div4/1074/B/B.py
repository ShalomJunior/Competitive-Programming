import sys

input = sys.stdin.readline


def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    mx = max(a)
    print(mx * n)


def main():
    t = int(input().strip())
    while t > 0:
        solve()
        t -= 1


if __name__ == "__main__":
    main()
