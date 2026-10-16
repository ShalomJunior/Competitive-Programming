#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(m);
    for (auto& c : b) cin >> c;
    sort(b.begin(), b.end());
    string s;
    cin >> s;
    vector<pair<int, int>> L(n, { INF, -1 });
    vector<pair<int, int>> R(n, { INF, -1 });
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        L[i].second = i;
        if (it != b.begin()) {
            it--;
            L[i].first = a[i] - *it;
        }
        it = upper_bound(b.begin(), b.end(), a[i]);
        R[i].second = i;
        if (it != b.end()) {
            R[i].first = *it - a[i];
        }
    }
    sort(L.rbegin(), L.rend());
    sort(R.rbegin(), R.rend());
    int j = 0;
    set<int> out;
    for (int i = 0; i < k; i++) {
        j += (s[i] == 'L' ? -1 : 1);
        if (j < 0) {
            while (!L.empty() && L.back().first <= -j) {
                out.insert(L.back().second);
                L.pop_back();
            }
        }
        else if (j > 0) {
            while (!R.empty() && R.back().first <= j) {
                out.insert(R.back().second);
                R.pop_back();
            }
        }
        else {}
        cout << n - out.size() << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}