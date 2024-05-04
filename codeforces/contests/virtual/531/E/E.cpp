#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int MOD = 998244353;

int merge(vector<Mine>& a) {
    int n = a.size();
    int ans = 0;
    int L = a[0].F, R = a[0].S;
    for (int i = 1; i < n; i++) {
        if (a[i].F <= R) R = max(R, a[i].S);
        else {
            ans++;
            L = a[i].F;
            R = a[i].S;
        }
    }
    return ++ans;
}

void solve() {
    int n; cin >> n;
    map<int, Mine> h;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (!h.count(a)) h[a].F = h[a].S = i;
        else h[a].S = i;
    }
    vector<Mine> vec;
    for (auto& [_, p] : h) {
        vec.push_back({ p.F, p.S });
    }
    sort(vec.begin(), vec.end());
    int e = merge(vec);
    int ans = 1;
    for (int i = 0; i < e - 1; i++) {
        ans = (ans * 2) % MOD;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}