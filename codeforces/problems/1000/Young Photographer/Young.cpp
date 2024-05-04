#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        if (s > e) swap(s, e);
        seg[i] = make_pair(s, e);
    }
    sort(seg.begin(), seg.end());

    int l = seg[0].first;
    int r = seg[0].second;
    for (int i = 1; i < n; i++) {
        if (seg[i].first > r) {
            cout << -1 << endl;
            return 0;
        }
        else {
            l = seg[i].first;
            r = min(r, seg[i].second);
        }
    }

    if (x >= l && x <= r)
        cout << 0 << endl;
    else
        cout << min(abs(x - l), abs(x - r)) << endl;

}