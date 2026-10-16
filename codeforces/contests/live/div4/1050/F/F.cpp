#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
void solve() {
    int n;
    cin >> n;
    int len = 0;
    vector<deque<int>> a(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        len = max(len, k);
        a[i].resize(k);
        for (int j = 0; j < k; j++) cin >> a[i][j];
    }
    set<int> data;
    for (int i = 0; i < n; i++) data.insert(i);
    auto in = data;
    vector<int> ans;
    for (int i = 0; i < len; ) {
        int mn = INF;
        set<int> nxt;
        set<int> del;
        for (auto& j : in) {
            if (a[j].size() <= i) {
                del.insert(j);
            }
            else {
                if (a[j][i] < mn) {
                    mn = a[j][i];
                    nxt.clear();
                    nxt.insert(j);
                }
                else if (a[j][i] == mn) {
                    nxt.insert(j);
                }
                else {}
            }
        }
        if (del.empty()) {
            ans.push_back(mn);
            in = nxt;
            i++;
        }
        else {
            for (auto& c : del) data.erase(c);
            in = data;
        }
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
