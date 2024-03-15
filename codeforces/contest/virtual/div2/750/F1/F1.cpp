#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 13;
const int M = 500;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<bool> dp(N), temp;
    vector<int> p(N, M + 1);
    dp[0] = true;
    p[0] = -1;
    for (int i = 0; i < n; i++) {
        temp = dp;
        for (int j = 0; j < N; j++) {
            if (p[j] && p[j] < a[i]) {
                temp[j ^ a[i]] = true;
                p[j ^ a[i]] = min(p[j ^ a[i]], a[i]);
            }
        }
        dp = temp;
    }
    int k = count(dp.begin(), dp.end(), true);
    cout << k << endl;
    for (int i = 0; i < N; i++) {
        if (dp[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

