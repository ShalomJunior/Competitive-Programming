import sys

input = sys.stdin.readline


class Fenwick:
    def __init__(self, size):
        self.arr = [0] * (size + 3)

    def add(self, index, val):
        arr = self.arr
        limit = len(arr)
        while index < limit:
            arr[index] += val
            index += index & (-index)

    def query(self, index):
        arr = self.arr
        total = 0
        while index > 0:
            total += arr[index]
            index -= index & (-index)
        return total

    def range_query(self, left, right):
        return self.query(right) - self.query(left - 1)


def solve():
    n, q = map(int, input().split())
    a = [0]
    a.extend(list(map(int, input().split())))
    fen = Fenwick(3 * n)
    for i in range(1, n + 1):
        fen.add(i, a[i])
        fen.add(i + n, a[i])

    for _ in range(q):
        l, r = map(int, input().split())
        f1 = (l + n - 1) // n
        g1 = l % n if l % n > 0 else n
        r1 = n - g1 + 1
        f2 = (r + n - 1) // n
        g2 = r % n if r % n > 0 else n
        r2 = g2
        tot = 0
        if f1 == f2:
            j = f1 + g1 - 1
            if j > n:
                j -= n
            tot += fen.range_query(j, j + r - l)
        else:
            cnt = f2 - f1 - 1
            tot += cnt * fen.range_query(1, n)
            j = f1 + g1 - 1
            if j > n:
                j -= n
            tot += fen.range_query(j, j + r1 - 1)
            tot += fen.range_query(f2, f2 + r2 - 1)
        print(tot)


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
