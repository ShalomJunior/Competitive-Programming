import sys

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a[0] = min(a[0], b[0] - a[0])
    for i in range(1, n):
        x = a[i]
        y = b[0] - a[i]
        if x > y:
            x, y = y, x
        if x >= a[i - 1]:
            a[i] = x
        else:
            a[i] = y
    print("YES" if a == sorted(a) else "NO")


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
