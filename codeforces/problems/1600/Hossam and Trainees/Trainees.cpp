#include <bits/stdc++.h>
using namespace std;

const int N = 4e4;
bitset<N> is_prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++)is_prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!is_prime[i])continue;
        primes.push_back(i);
        for (int j = i * i; j < N; j += i)is_prime.reset(j);
    }
}

set<int> s;
bool dec(int n) {
    int i = 0;
    while (n > 1 && i < primes.size()) {
        if (n < N && is_prime[n]) {
            if (s.count(n))return true;
            else { s.insert(n); return false; }
        }
        if (n % primes[i])i++;
        else {
            if (s.count(primes[i])) return true;
            else {
                s.insert(primes[i]);
                while (n % primes[i] == 0) n /= primes[i];  i++;
            }
        }
    }
    if (n > 1) {
        if (s.count(n)) return true;
        else s.insert(n);
    }
    return false;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (auto& c : a) {
        if (dec(c)) { cout << "YES" << endl; return; }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) {
        s = set<int>();
        solve();
    }
}