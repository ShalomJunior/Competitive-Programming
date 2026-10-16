import sys

input = sys.stdin.readline


N = 10
card = [[0] * N for _ in range(N)]


def solve():
    ans = 0
    for i in range(N):
        row = input().strip()
        for j in range(N):
            if row[j] == "X":
                ans += card[i][j]
    print(ans)


def main():
    for i in range(N // 2):
        for x in range(i, N - i):
            for y in range(i, N - i):
                card[x][y] = i + 1
                card[y][x] = i + 1

    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
