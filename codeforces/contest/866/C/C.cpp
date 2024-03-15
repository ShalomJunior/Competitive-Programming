#include <bits/stdc++.h>
using namespace std;

int mex(vector<int>& v) {
    int n = (int)v.size();
    unordered_set<int> s(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (!s.count(i)) {
            return i;
        }
    }
    return 1 + *max_element(v.begin(), v.end());
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);

    for (auto& c : v)cin >> c;

    int mx = mex(v);
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (v[i] == mx + 1)pos.push_back(i);
    }

    if ((int)pos.size() > 0) {
        for (int i = pos[0]; i <= pos.back(); i++) {
            v[i] = mx;
        }
    }
    else {
        cout << ((mx == n) ? "NO" : "YES") << endl;
        return;
    }
    cout << ((mex(v) == mx + 1) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}