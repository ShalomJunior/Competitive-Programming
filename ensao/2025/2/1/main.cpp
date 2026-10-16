#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    map<int, int> h;
    vector<pair<int, int>> ans;
    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        cout << pref[i] << " ";
        if (h.find(pref[i] - s) != h.end()) {
            ans.push_back({ h[pref[i] - s], i });
        }
        h[pref[i]] = i;
    }
    cout << endl;
    if (ans.empty()) {
        cout << "Empty list" << endl;
    }
    else {
        for (int j = ans[0].first + 1; j <= ans[0].second; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
    for (auto& c : a) cin >> c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}