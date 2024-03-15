#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    string s;
    cin >> n >> x >> s;
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (h == 0) {
                cout << "NO" << endl;
                return;
            }
            else h--;
        }
        else h = x;
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}