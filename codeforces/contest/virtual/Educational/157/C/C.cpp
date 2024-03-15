#include <bits/stdc++.h>
using namespace std;

const int N = 5;
void solve() {
    int n; cin >> n;
    vector<string> a(n);
    vector<vector<int>> cnt(N + 1, vector<int>(10 * N));
    for (auto& s : a) {
        cin >> s;
        int len = s.size(), sum = 0;
        for (auto& c : s) sum += c - '0';
        cnt[len][sum]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        for (int j = (len & 1 ? 1 : 2); j < len; j += 2) {
            int z = len + j;
            int sum1 = 0, sum2 = 0;
            for (int k = 0; k < len; k++) {
                int d = a[i][k] - '0';
                sum1 += (k < z / 2 ? d : -d);
                sum2 += (k >= len - z / 2 ? d : -d);
            }
            if (sum1 > 0) ans += cnt[j][sum1];
            if (sum2 > 0) ans += cnt[j][sum2];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < 10 * N; j++) {
            int m = cnt[i][j];
            ans += 1LL * m * (m - 1);
            ans += m;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}