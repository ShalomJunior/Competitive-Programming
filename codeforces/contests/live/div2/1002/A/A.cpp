#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    set<int> sa(a.begin(), a.end());
    set<int> sb(b.begin(), b.end());
    int l = sa.size();
    int r = sb.size();
    if (max(l, r) >= 3) {
        cout << "YES" << endl;
    }
    else if (min(l, r) == 1) {
        cout << "NO" << endl;
    }
    else {
        vector<int> xa, xb;
        for (auto& c : sa) xa.push_back(c), xa.push_back(c);
        for (auto& c : sb) xb.push_back(c), xb.push_back(c);
        sort(a.begin(), a.end());
        do {
            set<int> z;
            for (int i = 0; i < 4; i++) z.insert(xa[i] + xb[i]);
            if (z.size() >= 3) {
                cout << "YES" << endl;
                return;
            }
        } while (next_permutation(xa.begin(), xa.end()));
        cout << "NO" << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
