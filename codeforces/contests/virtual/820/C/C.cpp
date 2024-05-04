#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;


const int INF = 1e9;
void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = s[i] - 'a' + 1;
    }

    set<int> id;
    unordered_map<int, pair<int, int>> vals;

    int dp[n][2];
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        auto f = id.lower_bound(v[i]);
        auto s = id.upper_bound(v[i]);

        int diff = INF, difs = INF;
        if (f != id.end()) {
            diff = min(diff, *f - v[i]);
        }

        if (s != id.begin()) {
            s--;
            difs = min(difs, v[i] - *s);
        }

        if (diff < difs) {
            dp[i][0] = diff + vals[*f].F;
            dp[i][1] = 1 + vals[*f].S;
        }
        else if (difs < diff) {
            dp[i][0] = diff + vals[*s].F;
            dp[i][1] = 1 + vals[*s].S;
        }
        else {
            dp[i][0] = diff + vals[*f].F;
            dp[i][1] = 1 + max(vals[*f].S, vals[*s].S);
        }

        vals[v[i]].S = dp[i][1];
        id.insert(v[i]);
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}