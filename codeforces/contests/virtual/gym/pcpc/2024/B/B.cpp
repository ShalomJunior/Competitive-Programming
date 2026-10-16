#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

// #define LOCAL
#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...)
#endif

constexpr int md = 1e9 + 7;

i64 memo[200][10][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;cin >> tt;
    while (tt--) {
        string l, r; cin >> l >> r;
        int j = l.size() - 1;
        while (l[j] == '0') {
            l[j] = '9';
            j--;
        }
        l[j]--;
        while (l.size() < r.size()) l = '0' + l;
        string t; cin >> t;
        int n = l.size();
        string S;
        function<i64(int, char, bool)> dp = [&](int i, char c, bool less) {
            if (i == n - 1) {
                return 1ll;
            }
            if (memo[i][c - '0'][less] != -1)return memo[i][c - '0'][less];
            i64 rum = 0;
            if (t[i] == '<') {
                char mx = less ? '9' : S[i + 1];
                for (char c0 = c + 1; c0 <= mx; c0++) {
                    rum += dp(i + 1, c0, less || (c0 < mx));
                }
            }
            else {
                char mx = less ? '9' : S[i + 1];
                for (char c0 = min(char(c - 1), mx); c0 >= '0'; c0--) {
                    rum += dp(i + 1, c0, less || (c0 < mx));
                }
            }
            return memo[i][c - '0'][less] = rum % md;
            };
        i64 rum = 0;
        S = r;
        memset(memo, -1, sizeof(memo));
        for (char c = '0'; c <= r[0]; c++) {
            rum += dp(0, c, c < r[0]);
        }
        S = l;
        memset(memo, -1, sizeof(memo));
        for (char c = '0'; c <= l[0]; c++) {
            rum += md - dp(0, c, c < l[0]);
        }
        // rum -= dp(0, l, l[0], false);
        cout << rum % md << "\n";
    }

    return 0;

}
//9 36 4.5 8
//5 100 30.13 3.31
//1445 2200 40.38 54,48
