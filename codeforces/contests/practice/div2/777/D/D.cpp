#include<bits/stdc++.h>
using namespace std;

const int N = 2e6;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i) prime.reset(j);
    }
}

int dec(int n, map<int, int>& div) {
    int s = 0;
    for (auto& p : primes) {
        if (n < N && prime[n]) {
            s++;
            div[n]++;
            return s;
        }
        while (n % p == 0) {
            s++;
            div[p]++;
            n /= p;
        }
    }
    if (n > 1) div[n]++, s++;
    return s;
}

void solve() {
    int x, d;
    cin >> x >> d;
    int cnt = 0;
    while (x % d == 0) {
        cnt++;
        x /= d;
    }
    if (cnt > 1) {
        map<int, int> px;
        if (dec(x, px) > 1) {
            cout << "YES" << endl;
            return;
        }
        map<int, int> pd;
        int s = dec(d, pd);
        if (cnt < 3 || s < 2) {
            cout << "NO" << endl;
            return;
        }
        if (cnt > 3) {
            cout << "YES" << endl;
            return;
        }
        bool f = false;
        for (auto& [k, _] : pd) {
            if (x * k % d) f = true;
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}



/*

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i) prime.reset(j);
    }
}

int dec(int n, map<int, int>& div) {
    int s = 0;
    for (auto& p : primes) {
        if (n < N && prime[n]) {
            s++;
            div[n]++;
            return s;
        }
        while (n % p == 0) {
            s++;
            div[p]++;
            n /= p;
        }
    }
    if (n > 1) div[n]++, s++;
    return s;
}

void solve() {
    int x, d;
    cin >> x >> d;
    int cnt = 0;
    while (x % d == 0) {
        cnt++;
        x /= d;
    }
    cerr << "cnt = " << cnt << endl;
    if (cnt > 1) {
        map<int, int> px;
        if (dec(x, px) > 1) {
            cout << "YES" << endl;
            return;
        }
        map<int, int> pd;
        int s = dec(d, pd);
        if (cnt < 3 || s < 2) {
            cout << "NO" << endl;
            return;
        }
        if (cnt > 3) {
            cout << "YES#" << endl;
            return;
        }
        bool f = false;
        for (auto& [k, _] : pd) {
            if (x * k % d) f = true;
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}
*/