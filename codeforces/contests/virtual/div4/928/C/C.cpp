#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
vector<int> a(N);
vector<int> pre(N);
void init() {
    for (int i = 1; i < N; i++) {
        int x = i;
        while (x) {
            a[i] += x % 10;
            x /= 10;
        }
        pre[i] = pre[i - 1] + a[i];
    }
}

void solve() {
    int n; cin >> n;
    cout << pre[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--)solve();
}