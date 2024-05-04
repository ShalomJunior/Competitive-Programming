#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    bool flag = false;
    while (n) {
        a.push_back(n % 10);
        flag |= a.back() % 2 == 0;
        n /= 10;
    }
    if (flag) {
        if (a[0] % 2 == 0)cout << 0;
        else if (a.back() % 2 == 0)cout << 1;
        else cout << 2;
    }
    else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}