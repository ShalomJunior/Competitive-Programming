#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int cnt = count(a.begin(), a.end(), 0);
    if (cnt == n) {
        cout << 0 << endl;
        return;
    }
    int i = 0;
    while (a[i] == 0) i++;
    int j = n - 1;
    while (a[j] == 0) j--;
    int tot = i + n - 1 - j;
    cout << (tot == cnt ? 1 : 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
