#include <bits/stdc++.h>
using namespace std;

const int N = 4e4;
const int INF = 1e9;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++)prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i])continue;
        primes.push_back(i);
        for (int j = i * i; j < N; j += i)prime.reset(j);
    }
}

void dec(int n, map<int, int>& div) {
    int i = 0;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            div[n]++;
            return;
        }
        if (n % primes[i]) i++;
        else {
            while (n % primes[i] == 0) {
                div[primes[i]]++;
                n /= primes[i];
            }
            i++;
        }
    }
    if (n > 1) div[n]++;
}

void solve() {
    int a, b, k; cin >> a >> b >> k;
    if (k == 1) {
        int m = min(a, b);
        int M = max(a, b);
        cout << ((M % m == 0 && m % M != 0) ? "YES" : "NO") << endl;
        return;
    }
    map<int, int> xa, xb;
    dec(a, xa); dec(b, xb);
    int cnt = 0, common = 0;
    for (auto& [k, v] : xa) {
        int sub = (xb.count(k) ? xb[k] : 0);
        cnt += abs(v - sub);
        common += min(v, sub);
    }
    for (auto& [k, v] : xb) {
        if (!xa.count(k)) cnt += v;
    }
    cout << (cnt + 2 * common >= k ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}