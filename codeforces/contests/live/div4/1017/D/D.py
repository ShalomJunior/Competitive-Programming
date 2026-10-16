import sys

input = sys.stdin.readline


def solve():
    ps = input().strip()
    ss = input().strip()
    p = list(ps)
    s = list(ss)
    while p and s:
        c = p[-1]
        x = 0
        while p and p[-1] == c:
            p.pop()
            x += 1
        y = 0
        while s and s[-1] == c:
            s.pop()
            y += 1
        if x <= y and y <= 2 * x:
            pass
        else:
            print("NO")
            return
    print("NO" if p or s else "YES")


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
