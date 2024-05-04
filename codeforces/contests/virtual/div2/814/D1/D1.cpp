#include <bits/stdc++.h>
using namespace std;

const int N = 15;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    map<pair<int, int>, int> h;
    for (int j = 0; j < N; j++) {
        int mask = 1 << j;
        vector<int> p;
        for (int i = 0; i < n; i++) {
            p.push_back(a[i] & mask ? 1 : 0);
        }
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (p[i]) r = i;
            else {
                if (l < i) h[{l, r}]++;
                l = r = i + 1;
            }
        }
        if (l != r)h[{l, r}]++;
    }
    int ans = 0;
    for (auto& [k, v] : h) {
        int len = k.second - k.first + 1;
        ans += (len + 1) / 2;
        cout << k.first << " " << k.second << endl;
    }
    cout << "ans = " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}