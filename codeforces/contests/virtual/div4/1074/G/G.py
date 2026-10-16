import sys

input = sys.stdin.readline

INF = 10**9


def mex(s, nxt=INF):
    ans = 0
    while ans == nxt or ans in s:
        ans += 1
    return ans


def solve():
    n = int(input().strip())
    a = [[] for _ in range(n)]
    x = [0] * n
    y = [0] * n
    mpx = {}
    mpy = {}
    cnt = {}
    for i in range(n):
        line = list(map(int, input().split()))
        k = line[0]
        a[i] = line[1:]
        a[i].sort()
        s = set(a[i])
        x[i] = mex(s)
        y[i] = mex(s, x[i])
        cnt[x[i]] = cnt.get(x[i], 0) + 1
        mpx[x[i]] = mpx.get(x[i], 0) + x[i]
        mpy[x[i]] = mpy.get(x[i], 0) + y[i]
    all = sum(x)
    ans = 0
    for i in range(n):
        k = len(a[i])
        for j in range(k):
            mexx = x[i]
            if (j - 1 >= 0 and a[i][j - 1] == a[i][j]) or (
                j + 1 < k and a[i][j + 1] == a[i][j]
            ):
                pass
            else:
                mexx = min(x[i], a[i][j])
            yes = cnt.get(a[i][j], 0)
            no = n - 1 - yes
            ans += yes * (all + mexx - x[i]) + mpy.get(a[i][j], 0) - mpx.get(a[i][j], 0)
            ans += no * (all + mexx - x[i])
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
