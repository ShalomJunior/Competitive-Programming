#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    map<int, vector<vector<int>>> mp;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        int mx = INT_MIN;
        vector<int> v(k);
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            mx = max(mx, a);
            v[j] = a;
        }
        mp[mx].push_back(v);
    }

    int ans = 0;
    int last = mp.begin()->first;
    for (auto& [mx, vec] : mp) {
        cout << "mx = " << mx << endl;
        int best = 0;
        for (auto& tab : vec) {
            int curr = last;
            int temp = 0;
            for (auto& c : tab) {
                cout << c << "->";
                if (c > curr) {
                    temp++;
                    curr = c;
                }
            }
            cout << endl;
            best = max(best, temp);
        }
        ans += best;
        last = mx;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}