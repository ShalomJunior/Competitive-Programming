import sys

input = sys.stdin.readline


def solve():
    n, m, k = map(int, input().split())
    if abs(n - m) > k or max(n, m) < k:
        print(-1)
        return
    ans = ""
    i = 0
    while i + k <= min(n, m):
        ans += "0" * k
        ans += "1" * k
        i += k

    q = min(n, m) // k
    n -= q * k
    m -= q * k
    if n >= k:
        ans += "0" * k
        n -= k
    if m >= k:
        ans = "1" * k + ans
        m -= k
    while n or m:
        if len(ans) == 0 or ans[0] == "0":
            ans = "1" * m + ans
            m = 0
        else:
            ans = "0" * n + ans
            n = 0
        if len(ans) == 0 or ans[-1] == "0":
            ans += "1" * m
            m = 0
        else:
            ans += "0" * n
            n = 0
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
