#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string s;
    cin >> s;
    s = '#' + s;
    int n = s.size();
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    int k;
    cin >> k;
    vector<int> pref(n);
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[s[i] - 'a'];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            int cnt = pref[i] - pref[j - 1];
            if (cnt >= i - j + 1 - k) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
