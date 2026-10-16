import sys

input = sys.stdin.readline


def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    a = sorted(set(a))
    n = len(a)
    ans = 1
    length = 1
    for i in range(1, n):
        if a[i] == a[i - 1] + 1:
            length += 1
        else:
            ans = max(ans, length)
            length = 1

    ans = max(ans, length)
    print(ans)


def main():
    t = int(input().strip())
    while t > 0:
        solve()
        t -= 1


if __name__ == "__main__":
    main()
