#include <bits/stdc++.h>
using namespace std;

int query(set<int>& s) {
    cout << "? " << s.size() << " ";
    for (auto& c : s) cout << c + 1 << " ";
    cout << '\n';
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int q = 3 * n;
    int z = 2 * n;
    vector<int> ans(z);
    vector<bool> flag(z);
    set<int> s;
    for (int i = 0; i < z; i++) {
        s.insert(i);
        assert(--q >= 0);
        int res = query(s);
        if (res != 0) {
            flag[i] = true;
            ans[i] = res;
            s.erase(i);
        }
    }
    s.clear();
    for (int i = z - 1; i >= 0; i--) {
        s.insert(i);
        if (!flag[i]) {
            assert(--q >= 0);
            int res = query(s);
            if (res != 0) {
                ans[i] = res;
                s.erase(i);
            }
        }
    }
    cout << "! ";
    for (auto& c : ans) cout << c << " ";
    cout << '\n';
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
