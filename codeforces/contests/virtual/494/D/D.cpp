#include <bits/stdc++.h>
using namespace std;

const int N = 32;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[log2(x)]++;
    }
    while (q--) {
        int x; cin >> x;
        int cnt = 0;
        for (int i = N - 1; i >= 0; i--) {
            int q = x / (1 << i);
            int use = min(q, a[i]);
            cnt += use; x -= use * (1 << i);
        }
        cout << (x ? -1 : cnt) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}