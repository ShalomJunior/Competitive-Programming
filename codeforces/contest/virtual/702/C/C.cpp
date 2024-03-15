#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 5;
vector<int> cube(N);
set<int> in;

void solve() {
    int n; cin >> n;
    for (int i = 1; i < N; i++) {
        if (cube[i] > n) break;
        if (in.count(n - cube[i])) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N; i++) {
        cube[i] = i * i * i;
        in.insert(cube[i]);
    }
    int t; cin >> t;
    while (t--)solve();
}