#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const long long INF = 1e15;
void solve() {
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    vector<Mine> points = { {1, 1}, {1, m}, {n, 1}, {n, m} };
    auto go = [&](int f, int s) {
        long long ans = abs(points[f].F - i) + abs(points[f].S - j);
        ans += abs(points[f].F - points[s].F) + abs(points[f].S - points[s].S);
        return ans;
        };
    int x, y;
    long long cost = -1;
    for (int f = 0; f < 4; f++) {
        for (int s = 0; s < 4; s++) {
            long long c = go(f, s);
            if (c > cost) {
                cost = c;
                x = f, y = s;
            }
            c = go(s, f);
            if (c > cost) {
                cost = c;
                x = f, y = s;
            }
        }
    }
    cout << points[x].F << " " << points[x].S << " " << points[y].F << " " << points[y].S << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}