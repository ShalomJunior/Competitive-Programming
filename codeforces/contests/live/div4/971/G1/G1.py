import sys
from collections import defaultdict

input = sys.stdin.readline

import heapq
from collections import defaultdict


class Multiset:
    def __init__(self):
        self.min_heap = []
        self.max_heap = []
        # freq tracks the ACTUAL active count of elements
        self.freq = defaultdict(int)
        self.size = 0

    def insert(self, val):
        self.freq[val] += 1
        heapq.heappush(self.min_heap, val)
        heapq.heappush(self.max_heap, -val)
        self.size += 1

    def erase(self, val):
        # We only erase if it actually exists to avoid negative frequencies
        if self.freq[val] > 0:
            self.freq[val] -= 1
            self.size -= 1

    def get_min(self):
        # Clean up garbage (deleted elements) floating to the top
        while self.min_heap and self.freq[self.min_heap[0]] == 0:
            heapq.heappop(self.min_heap)

        return self.min_heap[0] if self.size > 0 else None

    def get_max(self):
        # Clean up garbage (deleted elements) floating to the top
        while self.max_heap and self.freq[-self.max_heap[0]] == 0:
            heapq.heappop(self.max_heap)

        return -self.max_heap[0] if self.size > 0 else None

    def __len__(self):
        return self.size


def solve():
    n, k, q = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(n):
        a[i] -= i
    h = defaultdict()
    for i in range(k - 1):
        h[a[i]] += 1
    curr = [0] * (n + 1)
    mx = set()
    for v in h:
        if v > 0:
            curr[v] += 1
            mx.add(v)
    cnt = [0] * n
    i = 0
    while i + k - 1 < n:
        j = i + k - 1
        if h[a[j]] > 0:
            curr[h[a[j]]] -= 1
            if curr[h[a[j]]] == 0:
                mx.discard(curr[h[a[j]]])
        h[a[j]] += 1
        curr[h[a[j]]] += 1
        mx.add(curr[h[a[j]]])
        cnt[i] = max(mx)
        curr[h[a[i]]] -= 1
        if curr[h[a[i]]] == 0:
            mx.discard(h[a[i]])
        h[a[i]] -= 1
        curr[h[a[i]]] += 1
        mx.add(curr[h[a[i]]])
        i += 1
    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        print(r - l + 1 - cnt[l])


def main():
    t = int(input().strip())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
