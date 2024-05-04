#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string num; int s;
    cin >> num >> s;
    int len = num.length(), sum = 0;
    for (int i = 0; i < len; i++) {
        if (sum + (num[i] - '0') <= s) sum += num[i] - '0';
        else {
            if (sum != s) {
                int v = stoll(num.substr(i, len - i));
                int M = pow(10, len - i);
                cout << M - v << endl;
                return;
            }
            for (int j = i - 1; j >= 0; j--) {
                if (num[j] != '0') {
                    int v = stoll(num.substr(j, len - j));
                    int M = pow(10, len - j);
                    cout << M - v << endl;
                    return;
                }
            }
        }
    }
    cout << 0 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}