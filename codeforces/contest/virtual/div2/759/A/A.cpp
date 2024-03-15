#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int len = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            a[i] ? len++ : len;
        }
        else {
            if (a[i]) {
                a[i - 1] ? len += 5 : len++;
            }
            else {
                if (a[i - 1] == 0) {
                    len = -1;
                    break;
                }
            }
        }
    }
    cout << len << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}