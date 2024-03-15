#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0, start = 0, i;
    for (i = 0; i < n; i++) {
        if (!i) { continue; }
        if (a[i] > a[i - 1]) {
            ans = max(ans, i - start);
            start = i;
        }
    }
    ans = max(ans, i - start);
    cout << ans << endl;
}