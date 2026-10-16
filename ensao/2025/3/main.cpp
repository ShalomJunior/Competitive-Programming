#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10;
const int INF = 1e18;
void solve() {
    int l, b;
    cin >> l >> b;
    string s;
    cin >> s;
    vector<int> a(l);
    for (int i = 0; i < l; i++) {
        if (s[i] == 'G') a[i] = 1;
        else if (s[i] == 'B') a[i] = 2;
        else {}
    }
    vector<vector<int>> ids(b);
    vector<vector<int>> from(l);
    for (int i = 0; i < b; i++) {
        int k;
        cin >> k;
        ids[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> ids[i][j];
            ids[i][j]--;
            from[ids[i][j]].push_back(i);
        }
    }
    int ans = INF;
    for (int i = 0; i < l; i++) {
        if (a[i] && from[i].empty()) {
            cout << "impossible" << endl;
            return;
        }
        int z = from[i].size();
        if (z == 1)
    }

    int tot = 0;
    bool f =
        for (int i = 0; i < b; i++) {

        }
    for (int j = 0; j < b; j++) {
        for (int k = 0; k < N; k++) {

        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}