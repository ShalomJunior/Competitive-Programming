#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2025;
vector<int> ans(N* N);
void prepare() {
    vector<vector<int>> L(N, vector<int>(N, 0)), R(N, vector<int>(N, 0));
    ans[1] = L[1][0] = R[1][1] = 1;
    int val = 1;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j < i; j++) {
            ++val;
            L[i][j] = L[i - 1][j] + val * val;
            R[i][i - j] = R[i - 1][i - j] + val * val;
            if (!j)ans[val] = L[i][j];
            else if (j == i - 1) ans[val] = R[i][i - j];
            else ans[val] = ans[val - 1] + L[i][j] - R[i][i - j + 1];
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << ans[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}