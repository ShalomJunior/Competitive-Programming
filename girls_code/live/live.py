def solve():
    n = int(input())

    ints = input().split(" ")

    v = 1
    for s in ints:
        v *= int(s)

    print(len(str(v)))


def main():
    T = int(input())
    while (T > 0):
        solve()
        T -= 1


if __name__ == '__main__':
    main()
