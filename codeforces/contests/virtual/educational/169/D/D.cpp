#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
bool in(string a, string b) {
    return b.find(a[0]) != string::npos || b.find(a[1]) != string::npos;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> c(n);
    map<string, vector<int>> ids;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        c[i] = s;
        ids[s].push_back(i);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (in(c[x], c[y])) {
            cout << abs(x - y);
        }
        else {
            int ans = INF;
            for (char& c1 : c[x]) {
                for (char& c2 : c[y]) {
                    stringstream ss;
                    ss << c1 << c2;
                    string k = ss.str();
                    auto& vec = ids[k];
                    auto it = lower_bound(vec.begin(), vec.end(), min(x, y));
                    if (it != vec.end()) {
                        if (*it < max(x, y))
                            ans = abs(y - x);
                        else
                            ans = min(ans, 2 * *it - x - y);
                    }
                    if (it != vec.begin()) {
                        it--;
                        ans = min(ans, x + y - 2 * *it);
                    }
                }
            }
            cout << (ans == INF ? -1 : ans);
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
