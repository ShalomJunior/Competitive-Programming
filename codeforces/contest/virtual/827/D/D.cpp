#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
void solve() {
    int n; cin >> n;
    vector<int> a, h(N, -1);
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        if (h[v] < 0) a.push_back(v);
        h[v] = max(h[v], i);
    }
    int ans = 0;
    int s = a.size();
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (gcd(a[i], a[j]) == 1) {
                ans = max(ans, h[a[i]] + h[a[j]]);
            }
        }
    }
    cout << ((ans) ? ans : -1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}