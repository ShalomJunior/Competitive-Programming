INF = 1e18

def get(a, k):
    n = len(a)
    if n == 0:
        return 0
    ans = 0
    until = -1
    for i in range(n):
        if a[i] > until:
            ans += 1
            until = a[i] + k - 1
    return ans

def solve():
    n, m = map(int, input().split())
    x, k, y = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    idx = [-1]
    match = 0
    i = 0
    j = 0
    while i < n and j < m:
        if a[i] == b[j]:
            idx.append(i)
            match += 1
            j += 1
        i += 1
    if match != m:
        print(-1)
        return
    idx.append(n)
    w = len(idx)
    ans = 0
    for i in range(1, w):
        l = idx[i - 1]
        r = idx[i]
        length = r - l - 1
        if length == 0:
            continue
        mx = max(a[l] if l != -1 else 0, a[r] if r != n else 0)
        sup = []
        M = 0
        for j in range(l + 1, r):
            if a[j] > mx:
                sup.append(j)
                M = max(M, a[j])
        need = get(sup, k)
        add = INF
        for c in range(length // k + 1):
            if c == 0 and M > mx:
                continue
            rem = length - c * k
            add = min(add, c * x + rem * y)
        if add == INF:
            print(-1)
            return
        ans += add
    print(ans)

solve()

