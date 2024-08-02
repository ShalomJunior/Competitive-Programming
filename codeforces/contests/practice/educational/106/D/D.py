import sys
import math
from typing import List
from collections import defaultdict

# Set recursion limit to a higher value (default is 1000)
sys.setrecursionlimit(10000000)

K = 20
N = 10**7 + 5
power = [1] * K
D = [-1] * N

prime = [True] * N
primes: List[int] = []

def prepare():
    global primes
    primes = []
    for i in range(2, N):
        if prime[i]:
            primes.append(i)
            for j in range(i * i, N, i):
                prime[j] = False

def dec(n: int) -> int:
    assert 0 < n < N
    if D[n] > -1:
        return D[n]
    if prime[n]:
        D[n] = 1
        return D[n]
    for p in primes:
        if n % p == 0:
            x = n
            while x % p == 0:
                x //= p
            D[n] = dec(x) + 1
            break
    assert 0 <= D[n] < K
    return D[n]


def init():
    prepare()
    for i in range(1, K):
        power[i] = power[i - 1] * 2
    D[1] = 0

def solve():
    c, d, x = map(int, input().split())
    ans = 0
    for i in range(1, int(math.sqrt(x)) + 1):
        if x % i == 0:
            g = i
            m = x // g + d
            if m % c == 0:
                m //= c
                ans += power[dec(m)]
            if g != x // g:
                g = x // g
                m = x // g + d
                if m % c == 0:
                    m //= c
                    ans += power[dec(m)]
    print(ans)

if __name__ == "__main__":
    import sys
    input = sys.stdin.readline
    init()
    t = int(input())
    for _ in range(t):
        solve()

