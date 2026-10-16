#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos, neg;
    for (auto& x : a) {
        cin >> x;
        x <= 0 ? neg.push_back(x) : pos.push_back(x);
    }
    sort(a.begin(), a.end());
    if (a[n - 1] == 0) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (s >= 0) {
            cout << neg.back();
            s += neg.back();
            neg.pop_back();
        }
        else {
            cout << pos.back();
            s += pos.back();
            pos.pop_back();
        }
        cout << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

