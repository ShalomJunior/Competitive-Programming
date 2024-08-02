#include <bits/stdc++.h>
#define int long long
#define Mine pair<int, int>
#define F first
#define S second
using namespace std;

const int N = 1e7;
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

void dec(int n, vector<Mine>& div) {
    int i = 0;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            div.push_back({ 1, n });
            return;
        }
        Mine add = { 0, primes[i] };
        while (n % primes[i] == 0) {
            add.F++;
            n /= primes[i];
        }
        if (add.F) div.push_back(add);
        i++;
    }
    if (n > 1) div.push_back({ 1, n });
}


int get(int x, int d) {
    int cnt = 0;
    while (x % d == 0) {
        cnt++;
        x /= d;
    }
    return cnt;
}

void solve() {
    int x, d;
    cin >> x >> d;
    int cnt = 0;
    int m = d * d;
    int j = 2;
    while (x % m == 0) {
        int q = x / m;
        cerr << j << " -> " << q << endl;
        vector<Mine> divs;
        dec(q, divs);
        int tot = 0;
        bool flag = true;
        for (auto& [v, p] : divs) {
            tot += v;
            flag &= p != d;
        }
        flag &= tot >= j;
        if (flag) {
            cnt++;
            if (tot > j) {

            }
        }
        m *= d;
        j++;
        cerr << "m = " << m << endl;
    }
    cerr << cnt << " #" << endl;
    cout << (cnt < 2 ? "NO" : "YES") << endl;
    cerr << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
