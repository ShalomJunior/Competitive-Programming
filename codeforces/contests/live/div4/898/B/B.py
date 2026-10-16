import sys

input = sys.stdin.readline


def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        k = 1
        for j in range(n):
            k *= a[j] + (1 if j == i else 0)
        ans = max(ans, k)
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
