#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (1 << (i + 1));
    }
    int s = accumulate(a.begin(), a.end(), 0);
    int r = a[n - 1] + accumulate(a.begin(), a.begin() + n / 2 - 1, 0);
    int l = s - r;
    cout << r - l << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}