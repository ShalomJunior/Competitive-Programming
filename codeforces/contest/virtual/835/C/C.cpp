#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int>v(n);
    for (auto& c : v)
        cin >> c;


    vector<int> ans(n);
    int mx = *max_element(v.begin(), v.end());
    multiset<int> s(v.begin(), v.end());
    s.erase(prev(s.end()));

    for (int i = 0; i < n; i++) {
        if (v[i] != mx) ans[i] = v[i] - mx;
        else ans[i] = v[i] - *prev(s.end());
    }


    for (auto& c : ans)
        cout << c << " ";
    cout << endl;
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}