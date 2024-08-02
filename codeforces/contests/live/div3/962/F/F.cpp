#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int score = 0;
    int overall = 0;
    int r = k;
    auto check = [&](int mid) {
        int cnt = 0;
        int s = 0;
        int dr = k;
        for (int i = 0; i < n; i++) {
            if (a[i] < mid) continue;
            int d = (a[i] - mid) / b[i];
            cnt += d + 1;
            dr -= d + 1;
            s += a[i] * (d + 1) - b[i] * (d * (d + 1) / 2);
        }
        if (cnt >= k) score = s, r = dr;
        overall = max(overall, s);
        return cnt >= k;
        };
    int L = 0, R = INF;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    if (L == 0) {
        cout << overall;
    }
    else {
        assert(r <= 0);
        score += L * r;
        cout << score;
    }
    cerr << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

/*
 score += L * r;
        cerr << L << " " << r << endl;
        cout << "#" << score << endl;
        assert(r <= 0);*/