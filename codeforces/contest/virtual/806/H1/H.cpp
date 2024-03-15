#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[i])ans++;
        }
        for (int j = i + 1; j < n; j++) {
            if (a[j] <= a[i])ans++;
        }
    }
    cout << ans / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}