#include <bits/stdc++.h>
using namespace std;

const int N = 32;
void solve() {
    int n, k; cin >> n >> k;
    int mn = __builtin_popcount(n);
    int mx = n;
    if (k < mn || k > mx) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int cnt = mn;
    for (int i = 0; i < N; i++) {
        int mask = 1 << i;
        if (n & mask) {
            if (cnt == k) {
                cout << mask << " ";
                continue;
            }
            else {
                if (cnt + mask - 1 <= k) {
                    cnt += mask - 1;
                    for (int j = 0; j < mask; j++) {
                        cout << 1 << " ";
                    }
                }
                else {
                    int r = k - cnt + 1;
                    multiset<int> ms;
                    ms.insert(mask);
                    while (ms.size() < r) {
                        int x = *prev(ms.end());
                        ms.erase(prev(ms.end()));
                        ms.insert(x / 2);
                        ms.insert(x / 2);
                    }
                    for (auto it = ms.begin(); it != ms.end(); it++) {
                        cout << *it << " ";
                    }
                    cnt = k;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}