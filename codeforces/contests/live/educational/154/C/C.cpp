#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            if (a.empty()) a.push_back(1);
            else {
                if (a.back() == 0) a.push_back(0);
                else a.push_back(-1);
            }
        }
        else if (s[i] == '-') {
            int m = a.size();
            if (m > 1 && a[m - 2] == -1 && a[m - 1] == 1) {
                a[m - 2] = 1;
            }
            a.pop_back();
        }
        else if (s[i] == '0') {
            if (a.empty() || a.back() == 1) {
                cout << "NO" << endl;
                return;
            }
            a.back() = 0;
        }
        else {
            if (!a.empty() && a.back() == 0) {
                cout << "NO" << endl;
                return;
            }
            if (!a.empty()) a.back() = 1;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}