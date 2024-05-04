#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, b, x;
    cin >> n >> b >> x;
    vector<int> c(n);
    for (auto& v : c) cin >> v;
    int tot = accumulate(c.begin(), c.end(), 0LL);
    auto go = [&](int mid) {
        int ans = 0;
        vector<int> t(mid);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mid; j++) {
                t[j] = c[i] / mid;
                if (j < c[i] % mid)t[j]++;
                if (j >= c[i] % mid && t[j] == 0)break;
            }
            for (int j = 0, r = c[i]; j < mid && t[j]; j++) {
                r -= t[j];
                ans += (t[j] * r) * b;
            }
        }
        return ans - (mid - 1) * x;
    };
    int L = 1, R = tot;
    while (L + 2 < R) {
        int len = (R - L) / 3;
        int l = L + len, r = R - len;
        go(l) < go(r) ? L = l : R = r;
    }
    int ans = 0;
    for (int i = L; i <= R; i++)ans = max(ans, go(i));
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
/*
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, b, x;
    cin >> n >> b >> x;
    vector<int> c(n);
    for (auto& v : c) cin >> v;
    int tot = accumulate(c.begin(), c.end(), 0LL);
    auto go = [&](int mid) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> t(mid, c[i] / mid);
            for (int j = 0; j < c[i] % mid; j++) t[j]++;
            for (int j = 0, r = c[i]; j < mid; j++) {
                r -= t[j];
                ans += (t[j] * r) * b;
            }
        }
        cout << "mid = " << mid << endl;
        cout << "ans  = " << ans - (mid - 1) * x << endl;
        return ans - (mid - 1) * x;
        };
    cout << "tot  = " << tot << endl;
    int L = 1, R = tot;
    while (L + 2 < R) {
        cout << L << " " << R << endl;
        int len = (R - L) / 3;
        int l = L + len, r = R - len;
        if (go(l) < go(r)) {
            L = r;
            cout << "pass" << endl;
        }
        else {
            R = r;
            cout << "here" << endl;
        }
    }
    cout << L << " ---> " << R << endl;
    int ans = 0;
    for (int i = L; i <= R; i++)ans = max(ans, go(i));
    cout << ans << endl << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}


*/