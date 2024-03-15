#include<bits/stdc++.h>
using namespace std;

void solve() {
    vector<char> a(6);
    for (auto& c : a) cin >> c;
    for (int i = 0; i < 4; i++) {
        if (a[i] == 'W' && a[i] == a[i + 1] && a[i] == a[i + 2]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}