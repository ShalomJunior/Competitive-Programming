#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), diff(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) diff[i - 1] = abs(a[i] - a[i - 1]);
    }
    sort(diff.rbegin(), diff.rend());
    cout << diff[0] + diff[1] + diff[2] << endl;
}