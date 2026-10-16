#include <bits/stdc++.h>
#define int long long 
#define double long double
using namespace std;

double log0(double x) {
    if (x == 0) {
        return -1e18;
    }
    return log(x);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 2) {
        if (a[1] >= a[2]) {
            cout << 2 << endl;
        }
        else {
            cout << 1 << endl;
        }
        return;
    }
    vector<double> pref1(n + 2, 0.0);
    for (int i = 2; i <= n; i += 2) {
        pref1[i] = pref1[i - 2] + log0(a[i - 1] ^ a[i]);
    }
    for (int i = 1; i <= n; i += 2) {
        pref1[i] = pref1[i - 1];
    }
    pref1[n + 1] = pref1[n];
    vector<double> pref2(n + 2, 0.0);
    for (int i = 3; i <= n; i += 2) {
        pref2[i] = pref2[i - 2] + log0(a[i - 1] ^ a[i]);
    }
    for (int i = 2; i <= n; i += 2) {
        pref2[i] = pref2[i - 1];
    }
    pref2[n + 1] = pref2[n];
    double total1 = pref1[n - (n % 2)];
    double total2 = pref2[n - ((n + 1) % 2)];
    double max_log_beauty = -1e19;
    int best_idx = -1;
    for (int i = 1; i <= n; i++) {
        double current_log_beauty = 0.0;
        int m = n - 1;
        if (i % 2 == 1) {
            current_log_beauty += pref1[i - 1];
            current_log_beauty += (total2 - pref2[i]);
        }
        else {
            current_log_beauty += pref1[i - 2];
            if (i + 1 <= n) {
                current_log_beauty += log0(a[i - 1] ^ a[i + 1]);
            }
            if (i + 1 <= n) {
                current_log_beauty += (total2 - pref2[i + 1]);
            }
        }
        if (m % 2 == 1) {
            if (i == n) {
                current_log_beauty += log0(a[n - 1]);
            }
            else {
                current_log_beauty += log0(a[n]);
            }
        }
        if (best_idx == -1 || current_log_beauty > max_log_beauty) {
            max_log_beauty = current_log_beauty;
            best_idx = i;
        }
    }
    cout << best_idx << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
}