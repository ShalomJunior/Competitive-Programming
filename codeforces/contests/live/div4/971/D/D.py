import sys

input = sys.stdin.readline


def solve():
    n = int(input().strip())
    h = {}
    cntx = 0
    cnty = 0
    for i in range(n):
        x, y = map(int, input().split())
        if x in h:
            h[x].add(y)
        else:
            h[x] = set([y])

        if y == 0:
            cntx += 1
        if y == 1:
            cnty += 1
    ans = 0
    for k, v in h.items():
        m = len(v)
        if m == 2:
            ans += cntx - 1
            ans += cnty - 1
        for y in v:
            if y == 0:
                if k - 1 in h and 1 in h[k - 1] and k + 1 in h and 1 in h[k + 1]:
                    ans += 1
            else:
                if k - 1 in h and 0 in h[k - 1] and k + 1 in h and 0 in h[k + 1]:
                    ans += 1
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
