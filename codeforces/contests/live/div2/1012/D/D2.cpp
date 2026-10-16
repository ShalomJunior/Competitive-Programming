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
    int z = (s + i - 1) / i;
    return prime[z];
}

void solve() {
    int n;
    cin >> n;
    set<int> all;
    for (int i = 1; i <= n; i++) all.insert(i);
    vector<int> p(n);
    int i = 0;
    int s = 0;
    for (auto& x : primes) {
        cout << x << "->" << endl;
        while (i < n) {
            int cnt = 0;
            cout << i << " " << x << endl;
            int r = max(i * x, 2LL);
            int l = max(r - i, 2LL);
            int add = l - s;
            cout << "add " << add << endl;
            cout << "l  " << l << endl;
            cout << "s = " << s << endl;
            auto it = all.lower_bound(add);
            if (it == all.end()) break;
            if (f(s + *it, i + 1)) {
                cnt++;
                p[i++] = *it;
                s += *it;
                all.erase(*it);
            }
            cout << all.size() << endl;
            vector<int> to;
            for (auto it = all.begin(); it != all.end(); it++) {
                if (*it <= r - s && f(s + *it, i + 1)) {
                    p[i++] = *it;
                    s += *it;
                    to.push_back(*it);
                }
            }
            for (auto& c : to) all.erase(c);
            // while (*it <= r - s && f(s + *it, i + 1)) {

            //     cout << "in" << endl;
            //     cout << *it << endl;
            //     p[i++] = *it;
            //     cout << "€" << *it << endl;
            //     cout << "gaùe" << endl;
            //     if (it == all.begin()) {
            //         all.erase(it);
            //         break;
            //     }
            //     else {
            //         int val = *it;
            //         it = prev(it);
            //         cout << "hell" << endl;
            //         all.erase(val);
            //     }
            // }
            if (!cnt) break;
            cout << "pass" << endl;
        }
    }
    cout << all.size() << endl;
    while (!all.empty()) {
        p[i++] = *all.begin();
        all.erase(all.begin());
    }
    for (auto& c : p) cout << c << " ";
    cout << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += prime[p[i]];
    }
    int mn = n / 3 - 1;
    cout << mn << " " << cnt << endl;
    assert(mn <= cnt);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
