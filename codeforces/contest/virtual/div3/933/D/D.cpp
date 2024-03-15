#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    int pos = x;
    vector<int> a;
    for (int i = 0; i < m; i++) {
        int r;
        char c;
        cin >> r >> c;
        if (c == '?')a.push_back(r);
        else {
            if (c == '0') pos = (pos + r) % n;
            else pos = (pos - r + n) % n;
            if (pos == 0) pos = n;
        }
    }
    set<int> ans;
    ans.insert(pos);
    for (auto& r : a) {
        set<int> temp;
        for (auto it = ans.begin(); it != ans.end(); it++) {
            int x1 = (*it + r) % n;
            int x2 = (*it - r + n) % n;
            temp.insert(x1 ? x1 : n);
            temp.insert(x2 ? x2 : n);
        }
        ans = temp;
    }
    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}