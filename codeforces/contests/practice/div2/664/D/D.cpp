#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second 
using namespace std;

void erase(set<int>& s) {
    s.erase(s.begin());
}

void solve() {
    int n; cin >> n;
    set<Mine> a;
    map<int, set<int>> id;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert({ i, x });
        id[x].insert(i);
    }
    set<int> dbles, ones;
    for (auto& [k, v] : id) {
        int m = v.size();
        if (m >= 2) dbles.insert(k);
        if (m & 1) ones.insert(k);
    }
    while (dbles.size()) {
        int val = *dbles.begin();
        int i = *id[val].begin(); erase(id[val]);
        int j = *(id[val].begin()); erase(id[val]);
        a.erase({ i, val }); a.erase({ j, val });
        int m = id[val].size();
        if (m == 1) {
            dbles.erase(val);
            ones.insert(val);
        }
        else if (m == 0) dbles.erase(val);
        Mine p = { j, val * 2 };
        a.insert(p); id[p.S].insert(j);
        if (ones.count(p.S)) {
            dbles.insert(p.S);
            ones.erase(p.S);
        }
        else ones.insert(p.S);
    }
    cout << a.size() << endl;
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << it->S << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
