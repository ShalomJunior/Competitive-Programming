#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> s(a.begin(), a.end());
    for (int i = 0; i <= N; i++) {
        int p = 1LL << i;
        for (auto& c : a) {
            if (s.count(c + p) && s.count(c + 2 * p)) {
                cout << 3 << endl;
                cout << c << " " << c + p << " " << c + 2 * p << endl;
                return;
            }
        }
    }
    for (int i = 0; i <= N; i++) {
        int p = 1LL << i;
        for (auto& c : a) {
            if (s.count(c + p)) {
                cout << 2 << endl;
                cout << c << " " << c + p << endl;
                return;
            }
        }
    }
    cout << 1 << endl << a[0] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}