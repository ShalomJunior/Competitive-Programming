#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (auto& c : a) cin >> c;
    multiset<int> ms(a.begin(), a.end());
    long long ans = 0;
    while (ms.size() > 1) {
        int mn = *ms.begin();
        int mx = *prev(ms.end());
        ms.erase(ms.begin());
        ms.erase(prev(ms.end()));
        if (mn == 1) {
            ms.insert(mx + 1);
            ans++;
        }
        else {
            ms.insert(mx + mn);
            ans += 2 * mn - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}