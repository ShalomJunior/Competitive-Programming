#include <bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll> 

using namespace std;

bool comp(pr a, pr b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int sup(vector<pr>& v, pr a) {
    auto it_l = lower_bound(v.begin(), v.end(), make_pair(a.first, 0), comp);
    auto it_r = lower_bound(v.begin(), v.end(), make_pair(a.first + 1, 0), comp);

    if (it_l == v.end() || it_r == v.begin())return -1;

    auto it = lower_bound(it_l, it_r - 1, a, comp);

    return v.begin() - it;
}

int inf(vector<pr>& v, pr a) {
    auto it_l = upper_bound(v.begin(), v.end(), a, comp);
}

void solve() {
    int n, q; cin >> n >> q;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        ll h, w; cin >> h >> w;
        v[i] = { h,w };
    }

    sort(v.begin(), v.end());

    ll cm = 0;
    vector<ll> cum(n);
    for (int i = 0; i < n; i++) {
        cm += v[i].first * v[i].second;
        cum[i] = cm;
    }

    for (int i = 0; i < q; i++) {
        int hmn, wmn, hmx, wmx;  cin >> hmn >> wmn >> hmx >> wmx;

        int idx1 = sup(v, { hmn + 1, wmn + 1 });
        int idx2 = sup(v, { hmx - 1, wmn - 1 });

        if (idx1 == 0) cout << cum[idx2] << endl;
        else cout << cum[idx2] - cum[idx1 - 1] << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}