#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto check = [&](int mid) {
        int mn = 0;
        for (int i = 0; i < n; i++) {
            int need = a[i] <= mn ? mn - a[i] : mn + m - a[i];
            if (need <= mid) continue;
            else {
                if (mn > a[i]) return false;
                mn = a[i];
            }
        }
        return true;
        };
    int L = 0, R = m;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << R << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}