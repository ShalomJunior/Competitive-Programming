#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
set<int> s;

void compute() {
    bitset<N> primes;
    primes.set();
    primes.reset(0); primes.reset(1);
    for (int i = 2; i < N; i++) {
        if (!primes[i])continue;
        for (int j = i * i; j < N; j += i) {
            primes.reset(j);
        }
    }
    for (int i = 0; i < N; i++) {
        if (primes[i]) s.insert(i);
    }
}

int main() {
    compute();

    int n, k; cin >> n >> k;
    unordered_map<int, int> h;
    for (auto it = s.begin(); it != prev(s.end()); it++) {
        h[1 + *it + *next(it)] = true;
    }

    int ans = 0;
    for (auto& [key, v] : h) {
        if (key <= n && s.find(key) != s.end())
            ans++;
    }
    cout << ((ans >= k) ? "YES" : "NO") << endl;
}