import sys

input = sys.stdin.readline


def solve():
    x, y, k = map(int, input().split())
    x1 = (x + k - 1) // k
    y1 = (y + k - 1) // k
    print(x1 * 2 - 1 if x1 > y1 else y1 * 2)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
