#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.rbegin(), a.rend());
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (s >= k) { cout << i + 1 << endl; return 0; }
    }
}