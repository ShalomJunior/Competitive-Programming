#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
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
        if (n % primes[i])i++;
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
    int n; cin >> n;
    map<int, int> div;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        dec(x, div);
    }
    for (auto& [k, cnt] : div) {
        if (cnt % n) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
