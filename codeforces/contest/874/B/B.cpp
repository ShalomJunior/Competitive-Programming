#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k; cin >> n >> k;
    vector<Mine> a(n);
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        a[i].F = v;
        a[i].S = i;
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    sort(b.begin(), b.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[a[i].S] = b[i];
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}