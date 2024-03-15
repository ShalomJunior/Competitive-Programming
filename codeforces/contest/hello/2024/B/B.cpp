#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int x = 0, y = 0;
    for (auto& c : s) {
        c == '+' ? x++ : y++;
    }
    cout << abs(x - y) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}