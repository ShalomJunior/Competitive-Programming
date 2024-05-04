#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int W, H;
    cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    bool x = w + x2 - x1 <= W;
    bool y = h + y2 - y1 <= H;
    int up = y1 >= h ? 0 : h - y1;
    int down = y2 <= H - h ? 0 : y2 - (H - h);
    int left = x2 <= W - w ? 0 : x2 - (W - w);
    int right = x1 >= w ? 0 : w - x1;
    int ans = INF;
    if (x) ans = min({ ans, left, right });
    if (y) ans = min({ ans, up, down });
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
