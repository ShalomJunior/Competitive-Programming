#include <bits/stdc++.h>
using namespace std;

void solve() {
    cerr << endl;
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (i + k < n ? s[i] != s[i + k] : 1);
    }
    vector<int> x(n), y(n);
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            x[i] = x[i - 1] + 1;
        }
        else {
            y[i] = y[i - 1] + 1;
        }
    }
    vector<int> X(n), Y(n);
    for (int i = 1; i < n; i++) {
        X[i] = max(X[i], x[i]);
        Y[i] = max(Y[i], y[i]);
    }
    vector<bool> b(n);
    multiset<char> ms(s.begin(), s.begin() + k - 1);
    for (int i = 0; i < n; i++) {
        if (i + k - 1 < n)ms.insert(s[i + k - 1]);
        b[i] = (int)ms.size() == k && *ms.begin() == *prev(ms.end());
        ms.erase(ms.find(s[i]));
    }
    for (int i = 1; i < n; i++) {
        if (b[i]) {
            cerr << "i  " << i << endl;
            int l = i + k;
            if (n - l < k) {
                int need = k - (n - l);
                if (s[i] == '0') {
                    if (Y[i - 1] >= need) {
                        int j = 0;
                        while (Y[j] < need) j++;
                        cout << "€" << j + 1 << endl;
                        return;
                    }
                }
                else {
                    if (X[i - 1] >= need) {
                        int j = 0;
                        while (X[j] < need) j++;
                        cout << "#" << j + 1 << endl;
                        return;
                    }
                }
            }
            else {
                if (a[i] != a[l] && b[l]) {
                    cout << 1 << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
