#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int t) {
    int n; cin >> n;
    multiset<ll> a;

    vector<pair<ll, ll>> b(n);

    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        a.insert(x);
        b[i] = { y, x };
    }
    /*
    if (t == 42) {
        for (int i = 0; i < n; i++) {
            cout << b[i].first << " " << b[i].second << " ";
        }
        cout << endl;
        return;
    }
    */
    sort(b.rbegin(), b.rend());

    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        bool bl = (b[0].first != 0 && b[0].second != 0);
        a.erase(a.find(b[i].second));

        auto it = lower_bound(a.begin(), a.end(), b[i].first);

        if (it == a.begin()) {
            if (b[i].first == 0 && bl && *it == 0) {
                a.insert(b[i].second);
                continue;
            }
            ans = min(ans, abs(*it - b[i].first));
        }
        else if (it == a.end()) {
            if (b[i].first == 0 && bl && *prev(it) == 0) {
                a.insert(b[i].second);
                continue;
            }
            ans = min(ans, abs(b[i].first - *prev(it)));
        }
        else {
            ll mn = min(abs(b[i].first - *it), abs(b[i].first - *prev(it)));
            if (b[i].first == 0 && bl && mn == 0) {
                a.insert(b[i].second);
                continue;
            }
            ans = min(ans, mn);
        }
        a.insert(b[i].second);
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    //while (t--)solve(t);
}