import sys
from collections import deque

sys.setrecursionlimit(300000)
input = sys.stdin.readline


def get_cycle(adj):
    x = -1
    n = len(adj)
    ans = set()
    vis = [0] * n
    parent = [0] * n

    def dfs(r, p):
        nonlocal x
        vis[r] = True
        parent[r] = p
        for c in adj[r]:
            if c == p:
                continue
            elif vis[c]:
                x = r
                ans.add(c)
                return True
            else:
                if dfs(c, r):
                    return True
        return False

    dfs(0, 0)
    curr = x
    while curr not in ans:
        ans.add(curr)
        curr = parent[curr]
    return ans


def solve():
    n, a, b = map(int, input().split())
    a -= 1
    b -= 1
    adj = [[] for _ in range(n)]
    for _ in range(n):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        adj[x].append(y)
        adj[y].append(x)
    if a == b:
        print("NO")
        return
    cycle = get_cycle(adj)
    da = [0] * n
    db = [0] * n
    q = deque()

    def bfs(r, dis):
        vis = [False] * n
        q = deque()
        q.append(r)
        dis[r] = 0
        vis[r] = True
        while q:
            x = q.popleft()
            for c in adj[x]:
                if vis[c]:
                    continue
                q.append(c)
                dis[c] = dis[x] + 1
                vis[c] = True

    bfs(a, da)
    bfs(b, db)
    run = -1
    for i in range(n):
        if i in cycle:
            if run == -1:
                run = i
            elif db[i] < db[run]:
                run = i

    print("YES" if not db[run] or db[run] < da[run] else "NO")


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
