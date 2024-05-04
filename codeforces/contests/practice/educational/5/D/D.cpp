#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int j = 0;
    vector<int> cnt(N);
    auto check = [&](int len) {
        for (int i = 0; i < N; i++) cnt[i] = 0;
        int z = 0;
        for (int i = 0; i < n; i++) {
            if (!cnt[a[i]]) z++;
            cnt[a[i]]++;
            if (i >= len - 1) {
                if (z <= k) {
                    j = i;
                    return true;
                }
                cnt[a[i + 1 - len]]--;
                if (cnt[a[i + 1 - len]] == 0) z--;
            }
        }
        return false;
        };
    int L = 1, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << j - L + 2 << " " << j + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
