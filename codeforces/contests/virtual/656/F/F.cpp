#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    map<int, int> h;
    for (int i = 0; i < n; i++) { int a; cin >> a; h[a]++; }

    vector<int> ans;
    for (auto& [a, v] : h) { if (v >= k)ans.push_back(a); }

    if (!ans.size()) { cout << -1 << endl; return; }

    vector<Mine> inter;
    int l = 0, r = 0;
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i] == ans[i - 1] + 1) r++;
        else {
            inter.push_back({ l, r });
            l = r = i;
        }
    }
    inter.push_back({ l,r });
    int L = 0, R = 0;
    for (auto p : inter) {
        if (ans[p.S] - ans[p.F] >= R - L) { L = ans[p.F], R = ans[p.S]; }
    }
    cout << L << " " << R << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}