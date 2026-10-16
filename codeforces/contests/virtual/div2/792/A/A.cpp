#include <bits/stdc++.h>
using namespace std;

const string P = "aeiuo";
const int M = 5;
void solve() {
    int n;
    cin >> n;
    string ans;
    for (int j = 0; j < M; j++) {
        ans += string(n / M, P[j]);
        if (j < n % M) ans += P[j];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}