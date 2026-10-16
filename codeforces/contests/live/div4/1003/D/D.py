import sys

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        row = list(map(int, input().split()))
        row.append(sum(row))
        a.append(row)
    a.sort(key=lambda x: x[-1], reverse=True)
    c = []
    for i in range(n):
        for j in range(m):
            c.append(a[i][j])

    k = n * m
    ans = 0
    for i in range(k):
        ans += (k - i) * c[i]
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
