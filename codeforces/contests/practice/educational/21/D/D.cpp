#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int tot = accumulate(a.begin(), a.end(), 0LL);
    if (tot & 1) {
        cout << "NO" << endl;
        return;
    }
    tot /= 2;
    auto check = [&](vector<int> b) {
        set<int> s = { 0 };
        for (int i = 0, sum = 0; i < n; i++) {
            sum += b[i];
            s.insert(b[i]);
            if (s.count(sum - tot)) return true;
        }
        return false;
        };
    if (check(a)) {
        cout << "YES";
    }
    else {
        reverse(a.begin(), a.end());
        cout << (check(a) ? "YES" : "NO");
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
