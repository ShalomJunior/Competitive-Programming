#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] += val;
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum += arr[index];
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] < a[j];
        });
    int d = (k + m - 1) / m;
    set<int> s;
    for (int i = 0; i < d; i++) s.insert(p[i]);
    vector<int> c;
    for (int i = 0; i < n; i++) {
        if (s.count(i)) c.push_back(a[i]);
    }
    fenwick<int> sum(d);
    for (int i = 0; i < d; i++) {
        sum.add(i + 1, c[i]);
    }
    int r = k % m;
    vector<int> cnt(d, m);
    if (r) cnt[d - 1] = r;
    fenwick<int> fen(d);
    for (int i = 0, s = 0; i < d; i++) {
        fen.add(i + 1, (c[i] + s) * cnt[i]);
        s += cnt[i];
    }
    int base = fen.query(d);
    int ans = base;
    if (r) {
        for (int i = 0; i < d - 1; i++) {
            int val = base - fen.rangeQuery(i + 1, i + 1) - fen.rangeQuery(d, d);
            val += (c[i] + i * m) * r + (c[d - 1] + k - m) * m;
            int len = d - 1 - i - 1;
            val -= len * (m - r) * m;
            ans = min(ans, val);
        }
    }
    cout << ans << endl;;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}


/*

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] += val;
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum += arr[index];
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] < a[j];
        });
    int d = (k + m - 1) / m;
    cerr << "d = " << d << endl;
    set<int> s;
    for (int i = 0; i < d; i++) s.insert(p[i]);
    vector<int> c;
    for (int i = 0; i < n; i++) {
        if (s.count(i)) c.push_back(a[i]);
    }
    for (auto& x : c) cerr << x << " -> ";
    cerr << endl;
    fenwick<int> sum(d);
    for (int i = 0; i < d; i++) {
        sum.add(i + 1, c[i]);
    }
    int r = k % m;
    vector<int> cnt(d, m);
    if (r) cnt[d - 1] = r;
    fenwick<int> fen(d);
    for (int i = 0, s = 0; i < d; i++) {
        fen.add(i + 1, (c[i] + s) * cnt[i]);
        s += cnt[i];
    }
    int base = fen.query(d);
    int ans = base;
    cerr << "nas = " << ans << endl;
    if (r) {
        cerr << "in" << r << k - r << endl;
        for (int i = 0; i < d - 1; i++) {
            int val = base - fen.rangeQuery(i + 1, i + 1) - fen.rangeQuery(d, d);
            cerr << val << " ";
            val += (c[i] + i * m) * r + (c[d - 1] + k - m) * m;
            cerr << val << " ";

            val -= sum.rangeQuery(i + 2, d - 1) * (m - r) * m;
            cerr << val << " ";
            cerr << endl;
            //cerr << val << " | ";
            ans = min(ans, val);
        }
        cerr << endl;
    }
    cout << ans << endl << endl;;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}*/