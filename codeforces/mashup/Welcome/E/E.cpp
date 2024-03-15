#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        mp[v]++;
    }

    int ans = 0;
    while (!mp.empty()) {
        int start = mp.begin()->first;
        while (mp.find(start) != mp.end()) {
            if (mp[start] == 1) mp.erase(start);
            else mp[start]--;
            start++;
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}