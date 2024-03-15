#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    multiset<long long> m;

    long long mx = 0;
    for (int i = 0; i < n; i++) {
        long long p; cin >> p;
        if (p == 0) {
            if (!m.empty()) {
                auto last = prev(m.end());
                mx += *last;
                m.erase(last);
            }
        }
        else
            m.insert(p);
    }
    cout << mx << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}