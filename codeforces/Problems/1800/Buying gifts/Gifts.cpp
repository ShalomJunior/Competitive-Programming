#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

const int INF = INT_MAX;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> b(n);
    multiset<pair<int, int>> rem;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = mp(x, i);
        rem.insert(mp(y, i));
        b[i] = y;
    }

    sort(a.begin(), a.end());

    int ans = INF;
    set<int> left;
    for (int i = 0; i < n; i++) {
        int curr = a[i].F, j = a[i].S;
        rem.erase(mp(b[j], j));

        int mx = INF;
        if (!rem.empty()) mx = prev(rem.end())->F;
        if (mx >= curr && mx != INF) {
            ans = min(ans, mx - curr);
        }
        else if (mx < curr || mx == INF) {
            if (mx != INF) ans = min(ans, curr - mx);
            auto f = left.lower_bound(curr);
            auto s = left.upper_bound(curr);

            int temp = INF;
            if (f != left.end())temp = *f - curr;
            if (s != left.begin()) {
                s--;
                temp = min(temp, curr - *s);
            }
            ans = min(ans, temp);
        }
        left.insert(b[j]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}