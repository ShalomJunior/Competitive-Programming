#include <bits/stdc++.h>
using namespace std;

const int M = 24 * 60;
const int N = 5;
const int INF = 1e9;

void go(int t, int tm, string a, int& dis, string& ans) {
    int h = t / 60;
    int m = t % 60;
    string sh = h < 10 ? "0" + to_string(h) : to_string(h);
    string sm = m < 10 ? "0" + to_string(m) : to_string(m);
    string p = sh + ":" + sm;
    for (int i = 0; i < N; i++) {
        if (a[i] == '?') continue;
        if (a[i] != p[i]) return;
    }
    int x = t <= tm ? tm - t : t + M - tm;
    int y = tm <= t ? t - tm : tm + M - t;
    if (min(x, y) < dis) {
        dis = min(x, y);
        ans = p;
    }
}

void solve() {
    string a, b;
    cin >> a >> b;
    int h = stoi(b.substr(0, 2));
    int m = stoi(b.substr(3, 2));
    int tm = 60 * h + m;
    int dis = INF;
    string ans;
    for (int i = 0; i < M; i++) {
        go(i, tm, a, dis, ans);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
