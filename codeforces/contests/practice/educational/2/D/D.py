import math
import sys

def solve():
    x1, y1, r1 = map(int, input().split())
    print("Solving")
    x2, y2, r2 = map(int, input().split())
    print("Read end")
    dx = x2 - x1
    dy = y2 - y1
    length = math.sqrt(dx ** 2 + dy ** 2)
    
    if r1 + r2 < length:
        print(0)
        return
    
    if length + min(r1, r2) <= max(r1, r2):
        print(math.pi * min(r1 ** 2, r2 ** 2))
        return
    
    d = (length + r1 + r2) / 2
    sub = 2 * math.sqrt(d * (d - r1) * (d - r2) * (d - length))
    w1 = (length ** 2 + r1 ** 2 - r2 ** 2) / (2 * length * r1)
    w2 = (length ** 2 + r2 ** 2 - r1 ** 2) / (2 * length * r2)
    print(w1 , w2)
    area = r1 ** 2 * math.acos(w1) + r2 ** 2 * math.acos(w2)
    print(area, sub)
    print(area-sub)
    print(f"{area - sub:.10f}")

if __name__ == "__main__":
    solve()

