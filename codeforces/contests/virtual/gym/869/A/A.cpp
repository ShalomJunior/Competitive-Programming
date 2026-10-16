#include <bits/stdc++.h>
using namespace std;

struct info {
    string s;
    int cnt;
    int pen;
    bool operator<(const info& o) const {
        if (cnt != o.cnt) return cnt > o.cnt;
        return pen < o.pen;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<info> a(n);
    for (auto& [s, cnt, pen] : a) {
        cin >> s >> cnt >> pen;
    }
    sort(a.begin(), a.end());
    cout << a[0].s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}