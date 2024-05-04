#include <bits/stdc++.h>
using namespace std;

int g(int n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 10;
    }
    return max(ans, 1);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    multiset<int> ma(a.begin(), a.end());
    multiset<int> mb(b.begin(), b.end());
    int ans = 0;
    while (!ma.empty()) {
        int x = *prev(ma.end());
        int y = *prev(mb.end());
        if (x == y) {
            ma.erase(ma.find(x));
            mb.erase(mb.find(y));
            continue;
        }
        ans++;
        if (x > y) {
            ma.erase(ma.find(x));
            ma.insert(g(x));
        }
        else {
            mb.erase(mb.find(y));
            mb.insert(g(y));
        }
    }
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
