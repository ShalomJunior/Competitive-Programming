#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    int save = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 && a[i - 1] > a[i]) {
            cnt++;
            if (a[i - 1] == a[i] + 1) save++;
        }
    }
    if (save) cnt--;
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}