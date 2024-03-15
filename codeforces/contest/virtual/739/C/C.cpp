#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e12;
vector<int> a;
void solve() {
    int k; cin >> k;
    auto it = lower_bound(a.begin(), a.end(), k);
    int m = it - a.begin() + 1;
    if (*it == k) cout << m << " " << 1;
    else {
        int rem = k - *(--it);
        int r = 0, c = m;
        if (rem <= m) r += rem;
        else {
            r = m;
            c -= (rem - m);
        }
        cout << r << " " << c;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a.push_back(1);
    int cum = 1;
    while (a.back() < N) {
        cum += 2;
        a.push_back(a.back() + cum);
    }
    int t; cin >> t;
    while (t--)solve();
}