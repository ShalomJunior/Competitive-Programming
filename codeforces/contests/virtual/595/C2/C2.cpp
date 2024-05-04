#include <bits/stdc++.h>
#define  int long long
using namespace std;

const int N = 5e18;
vector<int> p, pre;

void prepare() {
    int i = 1;
    do {
        p.push_back(i);
        pre.empty() ? pre.push_back(i) : pre.push_back(pre.back() + i);
        i *= 3;
    } while (i < N);
}

void solve() {
    int n; cin >> n;
    set<int> ans;
    int k = n;
    while (k) {
        auto it = upper_bound(p.begin(), p.end(), k); --it;
        int j = it - p.begin();
        if (pre[j] < k) {
            ans.insert(p[j + 1]);
            break;
        }
        k -= *it;
        ans.insert(*it);
    }
    int sum = accumulate(ans.begin(), ans.end(), 0LL);
    cout << sum << endl;
}

signed  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}