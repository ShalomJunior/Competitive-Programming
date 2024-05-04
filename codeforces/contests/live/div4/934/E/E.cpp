#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> lens;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            lens.push_back(i);
            lens.push_back(n / i);
        }
    }
    int ans = 1e9;
    for (auto& k : lens) {
        int mis = 0;
        for (int i = 0; i < k; i++) {
            vector<int> cnt(N);
            for (int j = i; j < n; j += k) {
                cnt[s[j] - 'a']++;
            }
            int mx = *max_element(cnt.begin(), cnt.end());
            mis += n / k - mx;
        }
        if (mis < 2)ans = min(ans, k);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
