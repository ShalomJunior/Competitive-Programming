#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int n) {
    return n * (n + 1) / 2;
}

int g(int x) {
    if (x == 0) return 0;
    int q = sqrtl(x * 2);
    while (f(q + 1) < x) q++;
    while (f(q - 1) >= x) q--;
    return q;
}

void solve() {
    int n, h, p;
    cin >> n >> h >> p;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    auto go = [&](int mid) {
        if (mid == 0) return true;
        if (p < a[mid] - a[0]) return false;
        int hm = h;
        int pm = p - (a[mid] - a[0]);
        multiset<int> ord;
        for (int i = 1; i <= mid; i++) {
            ord.insert(-b[i]);
        }
        while (!ord.empty()) {
            int v = -*ord.begin();
            ord.erase(ord.begin());
            int lo = 0, hi = min(pm, (int)2e6);
            while (lo < hi) {
                int m = (lo + hi) / 2;
                if (f(m) <= v) {
                    if (lo == m) f(hi) <= v ? lo = hi : hi = lo;
                    else lo = m;
                }
                else hi = m - 1;
            }
            pm -= lo;
            v -= f(lo);
            if (hm <= v) return false;
            hm -= v;
        }
        return true;
        };
    int L = 0, R = n - 1;
    while (L < R) {
        int mid = (L + R) / 2;
        if (go(mid)) {
            if (L == mid) go(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*

#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int n) {
    cerr << "n = " << n << endl;
    return n * (n + 1) / 2;
}

int g(int x) {
    if (x == 0) return 0;
    int q = sqrtl(x * 2);
    while (f(q + 1) < x) q++;
    while (f(q - 1) >= x) q--;
    return q;
}

void solve() {
    int n, h, p;
    cin >> n >> h >> p;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    auto go = [&](int mid) {
        cerr << "mid = " << mid << endl;
        if (mid == 0) return true;
        if (p - (a[mid] - a[0]) < 0) return false;
        int hm = h;
        int pm = p - (a[mid] - a[0]);
        cerr << "pm " << pm << endl;
        set<pair<int, int>> ord;
        for (int i = 0; i < mid; i++) {
            ord.insert({ -b[i], i });
        }
        while (!ord.empty()) {
            cerr << "ords" << ord.size() << endl;
            auto [v, j] = *ord.begin();
            v = -v;
            ord.erase(ord.begin());
            int q = min(g(v), pm);
            v -= f(q);
            pm -= q;
            if (v > 0) {
                if (hm <= v) return false;
                hm -= v;
            }
        }
        return true;
        };
    int L = 0, R = n - 1;
    while (L < R) {
        cerr << L << " -> " << R << endl;
        int mid = (L + R) / 2;
        if (go(mid)) {
            if (L == mid) go(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
*/