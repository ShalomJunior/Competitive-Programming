#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, m;
    string s;
    cin >> n >> k >> m >> s;
    vector<vector<int>> a(k);
    for (int i = 0; i < m; i++) {
        a[s[i] - 'a'].push_back(i);
    }
    bool flag = true;
    int start = 0;
    string bad;
    for (int i = 0; flag && i < n; i++) {
        int end = start;
        char let;
        for (int j = 0; j < k; j++) {
            auto it = lower_bound(a[j].begin(), a[j].end(), start);
            if (it == a[j].end()) {
                bad += (char)('a' + j);
                flag = false;
                break;
            }
            if (j == 0 || *it >= end)let = 'a' + j;
            end = max(end, *it);
        }
        if (flag)bad += let;
        start = end + 1;
    }
    if (flag) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
        while (bad.size() < n) bad += 'a';
        cout << bad << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
