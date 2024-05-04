#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int x = 1;
    while (a[x - 1] == x) x++;
    if (x <= n) {
        int j = 0;
        while (a[j] != x) j++;
        for (int i = x - 1; i < j; i++, j--) {
            swap(a[i], a[j]);
        }
    }
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}