#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end() - 1);
    auto check = [&](int i, int j, int k) {
        int x = a[i].first;
        int y = a[j].first;
        int z = a[k].first;
        return y - x == z - y;
        };
    vector<bool> L(n + 2, true);
    for (int i = 3; i <= n; i++) {
        if (!L[i - 1] || !check(i - 2, i - 1, i)) L[i] = false;
    }
    vector<int> R(n + 2, true);
    for (int i = n - 2; i > 0; i--) {
        if (!R[i + 1] || !check(i, i + 1, i + 2)) R[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (L[i - 1] && R[i + 1]) {
            if (i == 1 || i == n || n == 3) {
                cout << a[i].second << endl;
                return;
            }
            if (i > 2) {
                if (check(i - 2, i - 1, i + 1)) {
                    cout << a[i].second << endl;
                    return;
                }
            }
            else {
                if (check(i - 1, i + 1, i + 2)) {
                    cout << a[i].second << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
