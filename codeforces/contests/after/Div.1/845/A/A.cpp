#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int N = 1e4;
const int INF = 1e9;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (int j = i * i; j < N; j += i) prime.reset(j);
    }
}

void dec(int n, vector<Mine>& div) {
    int i = 0;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            div.push_back({ 1, n });
            return;
        }
        if (n % primes[i])i++;
        else {
            Mine add = { 0, primes[i] };
            while (n % primes[i] == 0) {
                add.F++;
                n /= primes[i];
            }
            div.push_back(add);
            i++;
        }
    }
    if (n > 1) div.push_back({ 1, n });
}

void solve() {
    int n; cin >> n;
    map<int, vector<int>> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vector<Mine> div;
        dec(x, div);
        for (auto& [cnt, p] : div) {
            h[p].push_back(cnt);
        }
    }
    int ans = 1;
    for (auto& [p, vec] : h) {
        int m = vec.size();
        if (m <= n - 2) continue;
        sort(vec.begin(), vec.end());
        ans *= pow(p, m == n ? vec[1] : vec[0]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    solve();
}
