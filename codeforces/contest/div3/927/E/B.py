def solve():
    l, r = map(int, input().split())
    d = r - l
    ans = 0
    past = 0
    p = 1
    while l or r:
        ans += d // p
        if d % p >= p - past:
            ans += 1
        past += (l % 10) * p
        l //= 10
        r //= 10
        p *= 10
    print(ans)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
