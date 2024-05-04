#include <bits/stdc++.h>
using namespace std;

const int INF = 2e8;
int best(vector<int>& a) {
    int n = a.size();
    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = a[i] + pre[i - 1];
    }
    multiset<int> ms(pre.begin(), pre.end());
    int ans = *prev(ms.end());
    ms.erase(ms.find(pre[0]));
    for (int i = 1; i < n; i++) {
        ans = max(ans, *prev(ms.end()) - pre[i - 1]);
        ms.erase(ms.find(pre[i]));
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = -INF;
    vector<int> tmp = { a[0] };
    for (int i = 1; i < n; i++) {
        if (abs(tmp.back() % 2) != abs(a[i] % 2))
            tmp.push_back(a[i]);
        else {
            ans = max(ans, best(tmp));
            tmp = { a[i] };
        }
    }
    if (!tmp.empty()) ans = max(ans, best(tmp));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
