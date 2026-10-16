import sys
import gc

gc.disable()
input = sys.stdin.readline


def merge(x):
    n = len(x)
    if n == 0:
        return
    x.sort()
    temp = []
    l = x[0][0]
    r = x[0][1]
    for i in range(1, n):
        if x[i][0] > r:
            temp.append((l, r))
            l = x[i][0]
            r = x[i][1]
        else:
            r = max(r, x[i][1])
    temp.append((l, r))
    x[:] = temp


def solve():
    n, k, x = map(int, input().split())
    p = list(map(int, input().split()))
    tels = list(range(k))

    def go(mid):
        nonlocal tels
        if mid == 0:
            return True
        till = []
        for c in p:
            till.append((max(c - mid + 1, 0), min(c + mid - 1, x)))
        merge(till)
        till.append((x + 1, x + 1))
        last = -1
        ntels = []
        for l, r in till:
            j = last + 1
            while j < l and len(ntels) < k:
                ntels.append(j)
                j += 1
            last = r
        if len(ntels) >= k:
            tels = ntels
            return True
        return False

    L = 0
    R = x + 1
    while L < R:
        mid = (L + R) // 2
        if go(mid):
            if L == mid:
                if go(R):
                    L = R
                else:
                    R = L
            else:
                L = mid
        else:
            R = mid - 1

    print(*tels)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
