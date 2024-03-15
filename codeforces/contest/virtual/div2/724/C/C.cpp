#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int d = 0, k = 0;
    map<pair<int, int>, int> h;
    for (int i = 0; i < n; i++) {
        s[i] == 'D' ? d++ : k++;
        int g = gcd(d, k);
        int dd = d / g, dk = k / g;
        h[{dd, dk}]++;
        cout << h[{dd, dk}] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}