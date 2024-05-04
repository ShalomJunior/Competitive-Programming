#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<Mine> seg(m);
    for (auto& [l, r] : seg) {
        cin >> l >> r;
        --l, --r;
    }
    int ans = 0, idi, idj;
    vector<int> id;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int cnt = 0;
            vector<int> save;
            int g = 0;
            for (auto& [l, r] : seg) {
                g++;
                if ((i < l || r < i) && (l <= j && j <= r)) {
                    save.push_back(g);
                    cnt++;
                }
            }
            cnt = a[i] - (a[j] - cnt);
            if (cnt > ans) {
                idi = i, idj = j;
                ans = cnt;
                id = save;
            }
        }
    }
    cout << ans << endl;
    cout << id.size() << endl;
    for (auto& c : id) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}