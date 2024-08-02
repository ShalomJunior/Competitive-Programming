#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    multiset<int> ms(a.begin(), a.end());
    int ans = 0;
    while (!ms.empty()) {
        int s = 0;
        while (true) {
            auto it = ms.upper_bound(s);
            if (it == ms.end()) break;
            s = *it;
            ms.erase(it);
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}