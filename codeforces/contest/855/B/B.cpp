#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    unordered_map<char, int>h;
    for (auto& c : s)
        h[c]++;

    int mx = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        int diff = abs(h[c] - h[toupper(c)]);
        if (diff != 0) {
            if (k >= diff / 2) {
                mx += (h[c] + h[toupper(c)]) / 2;
                k -= diff / 2;
            }
            else {
                mx += min(h[c], h[toupper(c)]) + k;
                k = 0;
            }
        }
        else {
            mx += h[c];
        }
    }
    cout << mx << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}