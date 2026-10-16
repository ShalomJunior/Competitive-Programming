import sys

input = sys.stdin.readline

N = 31


def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    cnt = [0] * N
    for i in range(n):
        for j in range(N):
            mask = 1 << j
            if a[i] & mask:
                cnt[j] += 1
    ans = 0
    for i in range(n):
        curr = 0
        for j in range(N):
            mask = 1 << j
            if a[i] & mask:
                curr += (n - cnt[j]) * mask
            else:
                curr += cnt[j] * mask
        ans = max(ans, curr)
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
