import sys

input = sys.stdin.readline

N = 200005

prime = [True] * N
primes = []


def prepare():
    prime[0] = prime[1] = False
    for i in range(2, N):
        if prime[i]:
            primes.append(i)
            for j in range(i * i, N, i):
                prime[j] = False


def dec(n):
    D = []
    i = 0
    limit = len(primes)
    while n > 1 and i < limit:
        if n < N and prime[n]:
            D.append((n, 1))
            return D
        cnt = 0
        p = primes[i]
        while n % p == 0:
            cnt += 1
            n //= p
        if cnt > 0:
            D.append((p, cnt))
        i += 1

    if n > 1:
        D.append((n, 1))

    return D


def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    ans = 0
    h = [0] * (n + 1)
    cnt = [0] * (n + 1)
    sgn = 0
    for i in range(n):
        x = a[i]
        D = dec(x)
        m = len(D)
        mx = 0
        for p, b in D:
            mx = max(mx, b)
        if m == 1:
            if D[0][1] == 1:
                cnt[x] += 1
                sgn += 1
                ans += sgn - cnt[x]
                if x * x <= n:
                    ans += cnt[x * x]
                ans += h[x]
            elif D[0][1] == 2:
                cnt[x] += 1
                ans += cnt[D[0][0]]
                ans += cnt[x]
            else:
                pass

        elif m == 2:
            if max(D[0][1], D[1][1]) == 1:
                cnt[x] += 1
                ans += cnt[D[0][0]]
                ans += cnt[D[1][0]]
                ans += cnt[x]
                h[D[0][0]] += 1
                h[D[1][0]] += 1
        else:
            pass
    print(ans)


def main():
    prepare()
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
