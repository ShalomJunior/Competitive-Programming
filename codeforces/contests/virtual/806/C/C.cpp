#include <bits/stdc++.h>
using namespace std;

void flip(string& s) { for (auto& c : s) { (c == 'D') ? c = 'U' : c = 'D'; } }
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        string s; cin >> s; flip(s);
        for (auto& c : s) {
            (c == 'U') ? a[i]++ : a[i]--;
            if (a[i] > 9) a[i] %= 10;
            else if (a[i] < 0) a[i] += 10;
        }
    }
    for (auto& c : a)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}