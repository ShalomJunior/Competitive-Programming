#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    --l, --r;
    int len = r - l + 1;
    int m = len * (len + 1) / 2;
    int M = len * (2 * n - len + 1) / 2;
    if (s < m || s > M) {
        cout << -1 << endl;
        return;
    }
    set<int> nums;
    for (int i = len + 1; i <= n; i++) nums.insert(i);
    vector<int> a(len);
    iota(a.begin(), a.end(), 1);
    int i = len - 1, to = n, sum = m;
    while (sum < s) {
        int d = s - sum;
        int delta = min(d, to - a[i]);
        sum += delta;
        nums.insert(a[i]);
        a[i] += delta;
        nums.erase(a[i]);
        to = a[i] - 1;
        --i;
    }
    for (int i = 0; i < n; i++) {
        if (i >= l && i <= r) cout << a[i - l] << " ";
        else {
            cout << *nums.begin() << " ";
            nums.erase(nums.begin());
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}