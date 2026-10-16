import sys
from collections import deque

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())
    s = input().strip()
    q = deque()
    for i in range(n):
        if s[i] == "B":
            q.append(i)
    if not q:
        print(0)
        return
    ans = 0
    while q:
        x = q[0]
        ans += 1
        while q and q[0] <= x + k - 1:
            q.popleft()
    print(ans)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
