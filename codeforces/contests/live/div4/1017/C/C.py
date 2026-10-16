import sys

input = sys.stdin.readline


def solve():
    n = int(input().strip())
    s = set(range(1, 2 * n + 1))
    p = [0] * (2 * n + 5)
    for i in range(1, n + 1):
        l = list(map(int, input().split()))
        for j in range(1, n + 1):
            p[i + j] = l[j - 1]
            s.discard(p[i + j])
    p[1] = min(s)
    print(*(p[1 : 2 * n + 1]))


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
