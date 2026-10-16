import sys

input = sys.stdin.readline


def solve():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))

    def go(mid):
        use = 0
        for i in range(n):
            if a[i] < mid:
                use += mid - a[i]
        return use <= x

    L = 1
    R = 2 * 10**9
    while L < R:
        mid = (L + R) // 2
        if go(mid):
            if L == mid:
                if go(mid + 1):
                    L = mid + 1
                else:
                    R = mid
            else:
                L = mid
        else:
            R = mid - 1
    print(L)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
