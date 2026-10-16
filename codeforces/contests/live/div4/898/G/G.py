import sys

input = sys.stdin.readline


def solve():
    s = input().strip()
    cnt = s.count("A")
    if s[0] == "B" or s[-1] == "B" or "BB" in s:
        print(cnt)
        return
    a = []
    sz = len(s)
    for i in range(sz):
        if s[i] == "A":
            if not a:
                a.append(1)
            else:
                if s[i - 1] == "B":
                    a.append(1)
                else:
                    a[-1] += 1

    a.sort()
    print(sum(a[1:]))


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
