#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5;
const int INF = 1e18;
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

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    ans.push_back(1);
    for (int p : primes) {
        if (p == 2) continue;
        while (ans.size() < n) {
            int nx = ans.back() * 2;
            if (nx < INF / (2 * p)) {
                ans.push_back(nx);
            }
            else {
                ans.push_back(nx * p);
                ans.push_back(p * 2);
                ans.push_back(p);
                ans.push_back(p * 4);
                break;
            }
        }
    }
    for (auto& c : ans) cout << c << ' ';
    cout << endl;

    set<int> check;
    for (int i = 0; i + 1 < n; i++) {
        cerr << ans[i] << ' ' << ans[i + 1] << ' ' << __gcd(ans[i], ans[i + 1]) << endl;
        if (check.count(__gcd(ans[i], ans[i + 1]))) {
            cout << "WRONG" << endl;
            cout << ans[i] << ' ' << ans[i + 1] << endl;
            cout << __gcd(ans[i], ans[i + 1]) << endl;
            return;
        }
        else {
            check.insert(__gcd(ans[i], ans[i + 1]));
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}