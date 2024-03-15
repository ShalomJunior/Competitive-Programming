#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
const T Max(const T& a, const T& b) {
    return max(a, b);
}

template<typename T>
const T Min(const T& a, const T& b) {
    return min(a, b);
}

template<typename T, const T(*op)(const T&, const T&)>
class sparseTable {
public:
    vector<vector<T>> st;
    sparseTable(vector<T> vals) {
        int n = vals.size();
        int rows = __lg(n) + 1;
        st.resize(rows);
        st[0] = vals;
        for (int j = 1; j < rows; j++) {
            st[j].resize(n);
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = __lg(r - l + 1);
        return op(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

int calc(int m) {
    return m * (m + 1) / 2;
}

void solve() {
    int n; cin >> n;
    vector<int> p1(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p1[x - 1] = i;
    }
    vector<int> p2(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p2[x - 1] = i;
    }
    sparseTable<int, Max> f1(p1);
    sparseTable<int, Min> g1(p1);
    sparseTable<int, Max> f2(p2);
    sparseTable<int, Min> g2(p2);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            int x = p1[0], y = p2[0];
            if (x > y)swap(x, y);
            ans += calc(x);
            ans += calc(y - x - 1);
            ans += calc(n - 1 - y);
            continue;
        }
        int l1 = g1.query(0, i - 1);
        int r1 = f1.query(0, i - 1);
        int l2 = g2.query(0, i - 1);
        int r2 = f2.query(0, i - 1);
        int l = min(l1, l2);
        int r = max(r1, r2);
        if ((l <= p1[i] && p1[i] <= r) || (l <= p2[i] && p2[i] <= r))continue;
        int x = -1;
        if (p1[i] < l)x = max(x, p1[i]);
        if (p2[i] < l)x = max(x, p2[i]);
        int y = n;
        if (p1[i] > r)y = min(y, p1[i]);
        if (p2[i] > r)y = min(y, p2[i]);
        x++; y--;
        x = l - x;
        y = y - r;
        ans += (x + 1) * (y + 1);
    }
    cout << ans << endl;
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

template<typename T>
const T Max(const T& a, const T& b) {
    return max(a, b);
}

template<typename T>
const T Min(const T& a, const T& b) {
    return min(a, b);
}

template<typename T, const T(*op)(const T&, const T&)>
class sparseTable {
public:
    vector<vector<T>> st;
    sparseTable(vector<T> vals) {
        int n = vals.size();
        int rows = __lg(n) + 1;
        st.resize(rows);
        st[0] = vals;
        for (int j = 1; j < rows; j++) {
            st[j].resize(n);
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = __lg(r - l + 1);
        return op(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

int calc(int m) {
    cout << "m = " << m << endl;
    return m * (m + 1) / 2;
}

void solve() {
    int n; cin >> n;
    vector<int> p1(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p1[x - 1] = i;
    }
    cout << "passed " << endl;
    vector<int> p2(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p2[x - 1] = i;
    }
    cout << "passed " << endl;

    sparseTable<int, Max> f1(p1);
    sparseTable<int, Min> g1(p1);
    sparseTable<int, Max> f2(p2);
    sparseTable<int, Min> g2(p2);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        cout << "i = " << i << endl;
        if (i == 0) {
            int x = p1[0], y = p2[0];
            if (x > y)swap(x, y);
            ans += calc(x);
            ans += calc(y - x - 1);
            ans += calc(n - 1 - y);
            continue;
        }
        int l1 = g1.query(0, i - 1);
        int r1 = f1.query(0, i - 1);
        int l2 = g2.query(0, i - 1);
        int r2 = f2.query(0, i - 1);
        int l = min(l1, l2);
        int r = max(r1, r2);
        if ((l <= p1[i] && p1[i] <= r) || (l <= p2[i] && p2[i] <= r))
            continue;
        int x = -1;
        if (p1[i] < l)x = max(x, p1[i]);
        if (p2[i] < l)x = max(x, p2[i]);
        int y = n;
        if (p1[i] > r) y = min(y, p1[i]);
        if (p2[i] > r) y = min(y, p2[i]);
        x++; y--;
        x = l - x;
        y = y - r;
        ans += (x + 1) * (y + 1);
        cout << x << " -> " << y << endl;
        // int x1, y1;
        // if (p1[i] < l1) {
        //     x1 = p1[i] + 1;
        //     y1 = n - 1;
        // }
        // else if (p1[i] > r1) {
        //     x1 = 0;
        //     y1 = p1[i] - 1;
        // }
        // else continue;
        // int x2, y2;
        // if (p2[i] < l2) {
        //     x2 = p2[i] + 1;
        //     y2 = n - 1;
        // }
        // else if (p2[i] > r2) {
        //     x2 = 0;
        //     y2 = p2[i] - 1;
        // }
        // else continue;
        // cout << l << " " << r << endl;
        // cout << l1 << " " << r1 << endl;
        // cout << l2 << " " << r2 << endl;
        // if (l <= r && (l <= l1 && r1 <= r) && (l <= l2 && r2 <= r)) {
        //     ans += r - l + 1 - (max(r1, r2) - min(l1, l2) + 1);
        // }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

*/