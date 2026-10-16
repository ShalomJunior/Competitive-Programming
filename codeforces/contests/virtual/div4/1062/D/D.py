import sys
from math import gcd

input = sys.stdin.readline

N = 1000
prime = [True] * N
primes = []


def prepare():
    prime[0] = False
    prime[1] = False
    for i in range(2, N):
        if not prime[i]:
            continue
        primes.append(i)
        for j in range(i * i, N, i):
            prime[j] = False


def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    for x in primes:
        for i in range(len(a)):
            if gcd(a[i], x) == 1:
                print(x)
                return
            else:
                a[i] //= x

    print(-1)


def main():
    prepare()
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
