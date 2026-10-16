#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
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

int f(int s, int i) {
    return (s + i - 1) / i;
}

void solve() {
    int n;
    cin >> n;
    set<int> all;
    for (int i = 1; i <= n; i++) all.insert(i);
    int s = 0;
    int i = 1;
    vector<int> ans(n + 1);
    for (auto& p : primes) {
        for (auto& c : all) {
            if (f(s + c, i) == p) {
                s += c;
                ans[i++] = c;
                all.erase(c);
                vector<int> to;
                for (auto& c : all) {
                    if (f(s + c, i) == p) {
                        s += c;
                        ans[i++] = c;
                        to.push_back(c);
                    }
                }
                for (auto& c : to) all.erase(c);
                break;
            }
        }
    }
    while (!all.empty()) {
        ans[i++] = *all.begin();
        all.erase(all.begin());
    }
    int cnt = 0;
    int pref = 0;
    for (int i = 1; i <= n; i++) {
        //cout << ans[i] << " ";
        pref += ans[i];
        cnt += prime[f(pref, i)];
    }
    cout << endl;
    int mn = n / 3 - 1;
    cout << mn << " " << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
