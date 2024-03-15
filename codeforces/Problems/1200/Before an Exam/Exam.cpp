#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, t; cin >> d >> t;
    vector<pair<int, int>> v(d);
    int smmn = 0, smmx = 0;
    for (auto& p : v) {
        int mn, mx; cin >> mn >> mx;
        p = { mn,mx };
        smmn += mn;
        smmx += mx;
    }
    if (smmn > t || smmx < t) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> ans(d);
    int res = t - smmn;
    for (int i = 0; i < d; i++) {
        if (res > 0) {
            int add = v[i].second - v[i].first;
            if (res >= add) {
                ans[i] = v[i].second;
                res -= add;
            }
            else {
                ans[i] = v[i].first + res;
                res = 0;
            }
        }
        else ans[i] = v[i].first;
    }

    cout << "YES" << endl;
    for (auto& c : ans)
        cout << c << " ";
    cout << endl;
}