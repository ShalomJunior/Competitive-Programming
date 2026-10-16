/*
This is not my soluion
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int full = (1 << m) - 1;
    vector<int> masks;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int mask = 0;
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            mask |= (1 << (t - 1));
        }
        masks.push_back(mask);
    }

    set<int> distinct_masks;
    for (int mask : masks) {
        if (mask != 0) {
            distinct_masks.insert(mask);
        }
    }

    vector<int> distinct_list(distinct_masks.begin(), distinct_masks.end());
    sort(distinct_list.begin(), distinct_list.end(), [](int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
        });

    vector<bool> cover(full + 1, false);
    cover[0] = true;
    vector<int> basis;
    for (int a : distinct_list) {
        if (cover[a]) continue;
        basis.push_back(a);
        for (int i = 0; i <= full; i++) {
            if (cover[i]) {
                cover[i | a] = true;
            }
        }
    }

    vector<int> dp(full + 1, INT_MAX);
    dp[0] = 0;
    for (int b : basis) {
        for (int s = full; s >= 0; s--) {
            if (dp[s] != INT_MAX) {
                int new_s = s | b;
                if (dp[new_s] > dp[s] + 1) {
                    dp[new_s] = dp[s] + 1;
                }
            }
        }
    }

    if (dp[full] == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << dp[full] << endl;
    }

    return 0;
}