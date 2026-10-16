#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int a = s.length();
    int b = t.length();
    int i = a;
    int j = b - 1;
    while (i >= 0 && j >= 0) {
        int k = i - 1;
        while (true) {
            while (k >= 0 && s[k] != t[j]) k--;
            if (k < 0) {
                cout << "NO" << endl;
                return;
            }
            int len = i - k - 1;
            if (len & 1) {
                k--;
            }
            else {
                j--;
                i = k;
                break;
            }
        }
    }
    cout << (j < 0 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}