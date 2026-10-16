#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> time;
    map<int, vector<int>> h;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        time.push_back(t);
        h[t].resize(n);
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            h[t][x - 1] = j;
        }
    }
    while (q--) {
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        y--;
        int j = upper_bound(time.begin(), time.end(), t) - time.begin();
        if (j == 0) {
            cout << (x < y ? x + 1 : y + 1) << endl;
        }
        else {
            int T = time[j - 1];
            cout << (h[T][x] < h[T][y] ? x + 1 : y + 1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}