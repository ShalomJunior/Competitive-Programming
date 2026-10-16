import sys

sys.setrecursionlimit(300000)
input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())
    adj = [[] for _ in range(n)]
    for i in range(1, n):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)

    tree = [[] for _ in range(n)]
    par = [-1] * n
    cnt = [1] * n
    under = [0] * n
    zoo = [0] * n
    vis = [False] * n

    def dfs(r):
        vis[r] = True
        for c in adj[r]:
            if not vis[c]:
                par[c] = r
                tree[r].append(c)
                dfs(c)
                zoo[r] += zoo[c]
                cnt[r] += cnt[c]
                under[r] += cnt[c]

        if cnt[r] >= k:
            zoo[r] += 1

    dfs(0)
    ans = [0] * n
    ans[0] = zoo[0]

    def go(r):
        if r != 0:
            p = par[r]
            ans[r] = ans[p]
            if cnt[r] < k:
                ans[r] += 1
            if n - cnt[r] < k:
                ans[r] -= 1
        for c in tree[r]:
            go(c)

    go(0)
    print(sum(ans))


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
