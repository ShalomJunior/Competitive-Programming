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
    int n, q; cin >> n >> q;
    map<int, int> div;
    dec(n, div);
    auto track = div;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            dec(x, track);
            long long cnt = 1;
            for (auto& [k, v] : track) cnt *= (v + 1);
            map<int, int> p;
            dec(cnt, p);
            bool done = false;
            for (auto& [k, v] : p) {
                if (!track.count(k) || track[k] < v) {
                    cout << "NO" << endl;
                    done = true;
                    break;
                }
            }
            if (done) continue;
            cout << "YES" << endl;
        }
        else track = div;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}
