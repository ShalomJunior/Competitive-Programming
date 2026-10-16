#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a, b, c, d;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 6 == 0) {
            a.push_back(x);
        }
        else if (x % 2 == 0) {
            b.push_back(x);
        }
        else if (x % 3 == 0) {
            c.push_back(x);
        }
        else {
            d.push_back(x);
        }
    }
    vector<int> ans(n);
    int l = 0, r = n - 1;
    for (int i = 0; i < a.size(); i += 2) {
        ans[l++] = a[i];
        if (i + 1 < a.size()) {
            ans[r--] = a[i + 1];
        }
    }
    if (a.size() % 2 == 1 && b.size() > c.size()) {
        swap(b, c);
    }
    for (int i = 0; i < b.size(); i++) {
        ans[l++] = b[i];
    }
    for (int i = 0; i < c.size(); i++) {
        ans[r--] = c[i];
    }
    for (int i = 0; i < d.size(); i++) {
        ans[l++] = d[i];
    }
    for (auto& v : ans) cout << v << " ";
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}