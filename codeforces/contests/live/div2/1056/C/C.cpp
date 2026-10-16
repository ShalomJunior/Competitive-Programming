#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (n == 1) {
        cout << (a[0] == 1 ? 2 : 0) << endl;
        return;
    }
    int i = 0;
    while (i + 1 < n && a[i] == a[i + 1]) i++;
    if (i == n - 1) {
        cout << 2 << endl;
    }
    else {
        vector<char> ans(n);
        ans[i] = ans[i + 1] = (a[i] < a[i + 1] ? 'L' : 'R');
        for (int j = i - 1; j >= 0; j--) {
            ans[j] = (ans[j + 1] == 'L' ? 'R' : 'L');
        }
        for (int j = i + 1; j + 1 < n; j++) {
            if (a[j] == a[j + 1]) {
                ans[j + 1] = (ans[j] == 'L' ? 'R' : 'L');
            }
            else {
                char c = (a[j] < a[j + 1] ? 'L' : 'R');
                if (c != ans[j]) {
                    cout << 0 << endl;
                    return;
                }
                ans[j + 1] = c;
            }
        }
        vector<int> X(n);
        for (int j = 0; j < n; j++) {
            X[j] = (ans[j] == 'L' ? 1 : 0);
            if (j > 0) {
                X[j] += X[j - 1];
            }
        }
        vector<int> Y(n);
        for (int j = n - 1; j >= 0; j--) {
            Y[j] = (ans[j] == 'R' ? 1 : 0);
            if (j + 1 < n) {
                Y[j] += Y[j + 1];
            }
        }
        for (int j = 0; j < n; j++) {
            int left = j == 0 ? 0 : X[j - 1];
            int right = j == n - 1 ? 0 : Y[j + 1];
            if (left + right + 1 != a[j]) {
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
