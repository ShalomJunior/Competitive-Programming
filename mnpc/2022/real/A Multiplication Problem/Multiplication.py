def main():
    inp = input().split()
    a, b, c = int(inp[0]), int(inp[1]), int(inp[2])

    if (a*b < c):
        print("No")
    else:
        print("Yes")


if __name__ == "__main__":
    main()
