#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, double> price;
    for (int i = 0; i < n; i++) {
        string s;
        double p;
        cin >> s >> p;
        price[s] = p;

    }
    double ans = 0;
    for (int i = 0; i < m; i++) {
        string s;
        double q;
        cin >> s >> q;
        ans += q * price[s];
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}