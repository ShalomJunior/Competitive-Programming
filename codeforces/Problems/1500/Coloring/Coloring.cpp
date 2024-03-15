#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m);
    int L = INF, R = 0;
    for (auto& c : a) {
        cin >> c;
        L = min(L, c);
        R = max(R, c);
    }

    int seg = n / k;
    if (n % k)seg++;
    if (m == k) {
        if (n % k) {
            int eq = 0, res = 0;
            for (auto& c : a) {
                if (c == n / k)eq++;
                else if (c == n / k + 1)res++;
            }
            cout << ((eq + res == m) ? "YES" : "NO") << endl;
            return;
        }
        else {
            cout << ((L == R) ? "YES" : "NO") << endl;
            return;
        }
    }

    cout << ((m < k || R > seg) ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}