#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0, sum = 0;;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i >= k) sum -= a[i - k];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}