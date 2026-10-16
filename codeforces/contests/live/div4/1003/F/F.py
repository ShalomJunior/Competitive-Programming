import sys

input = sys.stdin.readline


def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    adj = [[] for _ in range(n)]
    ans = ["0"] * n
    for i in range(1, n):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)
        if a[u] == a[v]:
            ans[a[u] - 1] = "1"

    last = [-1] * (n + 1)
    for i in range(n):
        for c in adj[i]:
            if last[a[c]] == i:
                ans[a[c] - 1] = "1"
            else:
                last[a[c]] = i

    print("".join(ans))


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
