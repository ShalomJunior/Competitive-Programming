#include <bits/stdc++.h>
using namespace std;

const int N = 5;
const int M = 2e4;
void solve() {
    vector<int> a(N);
    cin >> a[0] >> a[1] >> a[3] >> a[4];
    int ans = 0;
    for (int i = -M; i < M; i++) {
        a[2] = i;
        int curr = 0;
        for (int j = 2; j < N; j++) {
            curr += (a[j] == a[j - 1] + a[j - 2]);
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
