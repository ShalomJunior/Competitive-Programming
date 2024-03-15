import random


def main():
    n = 100000
    print(n)
    while (n > 0):
        print(random.randint(1, int(1e9)), " ", end=" ")
        n -= 1


if __name__ == '__main__':
    main()
