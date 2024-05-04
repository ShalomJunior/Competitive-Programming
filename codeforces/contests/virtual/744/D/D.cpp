#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    set<Mine> s;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) s.insert({ x, i + 1 });
    }
    int cnt = 0;
    stringstream ss;
    while (s.size() > 1) {
        Mine m = *s.begin();
        Mine M = *prev(s.end());
        s.erase(s.begin());
        s.erase(prev(s.end()));
        cnt++;
        ss << m.S << " " << M.S << endl;
        if (m.F > 1) s.insert({ m.F - 1, m.S });
        if (M.F > 1) s.insert({ M.F - 1, M.S });
    }
    cout << cnt << endl;
    cout << ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}