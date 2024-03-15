#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e15;

void solve() {
    int n; cin >> n;
    vector<ll>v(n);
    for (auto& c : v)cin >> c;

    v[n - 2] += INF - v[n - 1];
    v[n - 1] = INF;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] > v[i + 1]) {
            if (i == 0) {
                cout << "NO" << endl;
                return;
            }
            v[i - 1] -= (v[i] - v[i + 1]);
            v[i] = v[i + 1];
        }
        else {
            if (i > 0) {
                v[i - 1] += v[i + 1] - v[i];
                v[i] = v[i + 1];
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}