#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, sum; cin >> m >> sum;
    if (m * 9 < sum || (m > 1 && sum == 0)) { cout << "-1 -1" << endl; return; }
    if (!sum) { cout << "0 0" << endl; return; }
    vector<char> L(m);
    for (int t = sum, i = m - 1; i >= 0; i--) {
        if (t) {
            int d = min(t, 9);
            L[i] = '0' + d; t -= d;
        }
        else {
            L[i + 1]--;
            for (int j = i; j >= 0; j--) {
                j ? L[j] = '0' : L[j] = '1';
            }
            break;
        }
    }
    string mn = string(L.begin(), L.end());
    vector<char> R(m);
    for (int t = sum, i = 0; i < m; i++) {
        int d = min(t, 9);
        R[i] = '0' + d;
        t -= d;
    }
    string mx = string(R.begin(), R.end());
    cout << mn << " " << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}