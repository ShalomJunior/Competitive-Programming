#include <bits/stdc++.h>
using namespace std;

vector<int> query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    vector<int> ans;
    for (int i = l; i <= r; i++) {
        int x; cin >> x;
        ans.push_back(x);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int L = 1, R = n;
    auto check = [&](int mid) {
        auto vec = query(1, mid);
        int good = 0;
        for (auto& c : vec) {
            if (c <= mid)good++;
        }
        return good & 1;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << "! " << R << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
