#include <bits/stdc++.h>
using namespace std;

const int N = 31;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(N);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = 0; j < N; j++) {
            if (a & (1 << j)) v[j]++;
        }
    }
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        int add = n - v[i];
        if (k >= add) {
            ans |= (1 << i);
            k -= add;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}