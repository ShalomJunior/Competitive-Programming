#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    set<long long> s = { 0 };
    long long c = 0;
    for (int i = 0; i < n; i++) {
        c += a[i];
        if (s.count(c)) {
            ans++;
            c = a[i];
            s = { 0 , a[i] };
        }
        else s.insert(c);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}