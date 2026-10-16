#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> x_or(n);
    for (int i = 0; i < n; i++) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        x_or[i] = x ^ y;
    }
    int cnt = count(x_or.begin(), x_or.end(), 0);
    if (cnt == 0 || cnt == n) {
        cout << "YES" << endl;
        int k = 0;
        stringstream ss;
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i] - '0';
            if (x_or[i] ^ (k & 1)) {
                ss << 1 << " " << i + 1 << endl;
                k++;
            }
        }
        cout << k << endl;
        cout << ss.str();
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}