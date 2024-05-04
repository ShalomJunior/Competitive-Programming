#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    multiset<int> ms(b.begin(), b.end());
    vector<bool> in(n);
    int ans = 0;
    map<int, queue<int>> no;
    for (int i = 0; i < n; i++) {
        in[i] = !ms.empty() && ms.find(a[i]) != ms.end();
        if (in[i]) ms.erase(ms.find(a[i]));
        else no[a[i]].push(i);
        if (i >= m - 1) {
            if (ms.size() <= m - k) ans++;
            int j = i + 1 - m;
            if (in[j]) {
                if (no[a[j]].empty())
                    ms.insert(a[j]);
                else {
                    int p = no[a[j]].front();
                    no[a[j]].pop();
                    in[p] = true;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
