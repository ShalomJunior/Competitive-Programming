import sys

input = sys.stdin.readline

INF = 10**18


def solve():
    n, k = map(int, input().split())
    tot = n * (k + k + n - 1) // 2
    L = 1
    R = n

    def f(mid):
        x = mid * (k + k + mid - 1) // 2
        y = tot - x
        return x - y

    while L < R:
        mid = (L + R) // 2
        if f(mid) <= 0:
            if L == mid:
                if f(R) <= 0:
                    L = R
                else:
                    R = L
            else:
                L = mid
        else:
            R = mid - 1
    ans = INF
    ans = min(ans, abs(f(L)))
    ans = min(ans, f(L + 1))
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
