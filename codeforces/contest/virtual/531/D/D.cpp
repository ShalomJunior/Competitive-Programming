#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    int last;
    for (auto it = s.begin(); it != s.end(); it++) {
        int a = *it;
        if (!s.count(a * 2) && (a % 3 || (a % 3 == 0) && !s.count(a / 3))) {
            last = a;
            break;
        }
    }
    vector<int> ans(n);
    ans[n - 1] = last; s.erase(last);
    for (int i = n - 2; i >= 0; i--) {
        if (s.count(ans[i + 1] / 2)) ans[i] = ans[i + 1] / 2;
        else  ans[i] = ans[i + 1] * 3;
        s.erase(ans[i]);
    }
    for (auto& c : ans)cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}