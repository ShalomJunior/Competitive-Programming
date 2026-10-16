import sys

input = sys.stdin.readline


def solve():
    n = int(input().strip())
    for i in range(n):
        print(i + 1, end=" ")
    print()


def main():
    t = int(input().strip())
    while t > 0:
        solve()
        t -= 1


if __name__ == "__main__":
    main()
