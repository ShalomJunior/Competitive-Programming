#include <bits/stdc++.h>
#define  int long long
using namespace std;

vector<int> get(int d) {
    vector<int> ans;
    int k = d;
    while (k) {
        ans.push_back(k);
        k = (k + d) % 10;
    }
    ans.push_back(0);
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a = get(m % 10);
    int z = a.size();
    int q = n / m;
    int rounds = q / z;
    int ans = rounds * accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < q % z; i++) ans += a[i];
    cout << ans << endl;
}

signed  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}