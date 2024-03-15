#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    vector<int> a(7);
    for (auto& c : a) cin >> c;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            for (int k = j + 1; k < 7; k++) {
                if (a[i] + a[j] + a[k] == a[6]) {
                    cout << a[i] << " " << a[j] << " " << a[k] << endl;
                    return;
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}