import sys

input = sys.stdin.readline


def solve():
    n, m, h = map(int, input().split())
    a = list(map(int, input().split()))
    up = a[:]
    last = [0] * n
    curr = 1
    for _ in range(m):
        b, c = map(int, input().split())
        b -= 1
        if last[b] == curr:
            up[b] += c
        else:
            up[b] = a[b] + c
            last[b] = curr

        if up[b] > h:
            curr += 1

    ans = [up[i] if last[i] == curr else a[i] for i in range(n)]
    print(*ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
