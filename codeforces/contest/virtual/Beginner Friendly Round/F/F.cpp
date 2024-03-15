#include <bits/stdc++.h>
using namespace std;

const int N = 200;
vector<int> cum(N);

void solve() {
    int n; cin >> n;
    string ans;
    int i = 0;
    while (n) {
        auto it = upper_bound(cum.begin(), cum.end(), n); --it;
        n -= *it;
        int cnt = it - cum.begin();
        for (int j = 0; j < cnt; j++) ans += 'a' + i;
        i = (i + 1) % 26;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < N; i++) cum[i] = i * (i + 1) / 2;
    int t; cin >> t;
    while (t--)solve();
}