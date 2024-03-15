#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    set<Mine> wg;
    int last;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!i || (i && a[i] < last)) {
            wg.insert({ i, a[i] });
            last = a[i];
        }
    }
    while (q--) {
        int i, d; cin >> i >> d; i--;
        int sp = a[i] - d;
        auto it = wg.lower_bound({ i, 0 });
        if (it == wg.end() || (it != wg.end() && it->F != i)) {
            it--;
        }
        if (it->S <= sp) {
            cout << wg.size() << " ";
            a[i] -= d;
            continue;
        }
        vector<Mine> del;
        if (it->F != i)it++;
        while (it != wg.end() && it->S >= sp) {
            del.push_back(*it);
            it++;
        }
        for (auto& cp : del) {
            wg.erase(cp);
        }
        wg.insert({ i, sp });
        a[i] -= d;
        cout << wg.size() << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}