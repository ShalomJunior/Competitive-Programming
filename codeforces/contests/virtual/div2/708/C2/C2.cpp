#include <bits/stdc++.h>
using namespace std;

void f(int n) {
    if (n == 3) cout << "1 1 1";
    else if (n == 4) cout << "1 1 2";
    else if (n & 1) {
        cout << 1 << " " << (n - 1) / 2 << " " << (n - 1) / 2;
    }
    else {
        if (n % 4 == 2)
            cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2;
        else {
            if (n % 8 == 0)
                cout << n / 4 << " " << n / 4 << " " << n / 2;
            else
                cout << 4 << " " << (n - 4) / 2 << " " << (n - 4) / 2;
        }
    }
    cout << endl;
}

void g(int n) {
    switch (n % 4) {
    case 0:
        for (int i = 0; i < 4; i++) cout << n / 4 << " ";
        break;
    case 1:
        cout << 1 << " " << n / 4 << " " << n / 4 << " " << n / 2;
        break;
    case 2:
        cout << 1 << " " << 1 << " " << (n - 2) / 2 << " " << (n - 2) / 2;
        break;
    case 3:
        cout << 1 << " " << 2 << " " << (n - 3) / 2 << " " << (n - 3) / 2;
    default:
        break;
    }
    cout << endl;
}

void h(int n, int k) {
    vector<int> ans(k, 1);
    if (n == k);
    else if (n % 2 == k % 2) {
        int x = n - (k - 2);
        ans[k - 2] = ans[k - 1] = x / 2;
    }
    else {
        int r = n - (k - 1);
        ans[k - 3] = 2;
        if (r % 4 == 0) {
            ans[k - 2] = ans[k - 1] = r / 2;
        }
        else {
            if (r == 2);
            else {
                ans[0] = ans[1] = 2;
                int x = r - 2;
                ans[k - 2] = ans[k - 1] = x / 2;
            }
        }
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    switch (k) {
    case 3: f(n); break;
    case 4: g(n); break;
    default:
        h(n, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}