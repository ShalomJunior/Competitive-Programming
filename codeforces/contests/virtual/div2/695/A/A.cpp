#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
string ans;
void solve() {
    int n; cin >> n;
    cout << ans.substr(0, n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ans += "989";
    for (int i = 0; i < N; i++) {
        ans += '0' + i % 10;
    }
    int t; cin >> t;
    while (t--)solve();
}