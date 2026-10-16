import sys

input = sys.stdin.readline


def solve():
    a, b, c = input().split()
    print(a[0] + b[0] + c[0])


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
