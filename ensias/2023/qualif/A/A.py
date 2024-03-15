import math

def solve(n):
    h = (-1 + math.sqrt(1 + 8 * n)) / 2
    h1 = int(h)
    h2 = h1 + (n - (h1 * (h1 + 1)) / 2)
    return (h1, h2)

n = int(input().strip())
print(*solve(n))
