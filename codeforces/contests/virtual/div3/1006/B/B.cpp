#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int x = count(s.begin(), s.end(), '-');
    int y = n - x;
    int l = x / 2;
    int r = x - l;
    cout << 1LL * l * y * r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}