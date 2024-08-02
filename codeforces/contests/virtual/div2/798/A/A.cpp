#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    vector<char> x(a.begin(), a.end());
    vector<char> y(b.begin(), b.end());
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    string ans;
    int la = k, lb = k;
    while (!x.empty() && !y.empty()) {
        if (x.back() < y.back()) {
            if (la) {
                ans += x.back();
                x.pop_back();
                la--;
                lb = k;
            }
            else {
                ans += y.back();
                y.pop_back();
                lb--;
                la = k;
            }
        }
        else {
            if (lb) {
                ans += y.back();
                y.pop_back();
                lb--;
                la = k;
            }
            else {
                ans += x.back();
                x.pop_back();
                la--;
                lb = k;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}