#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    map<int, int> ca, cb;
    map<int, map<int, int>> cnt;
    for (int i = 0; i < n; i++) { cin >> a[i]; ca[a[i]]++; }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cb[b[i]]++;
        cnt[a[i]][b[i]]++;
    }
    vector<int> M(n); M[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        M[i] = max(b[i], M[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ca[a[i]] == 1)ca.erase(a[i]);
        else ca[a[i]]--;
        if (cb[b[i]] == 1)cb.erase(b[i]);
        else cb[b[i]]--;
        cnt[a[i]][b[i]]--;
        for (int j = 1; a[i] * j <= b[i] + M[i + 1]; j++) {
            if (ca[j] && cb[a[i] * j - b[i]]) {
                ans += cnt[j][a[i] * j - b[i]];
            }
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