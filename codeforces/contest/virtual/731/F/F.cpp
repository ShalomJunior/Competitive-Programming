#include <bits/stdc++.h>
using namespace std;

template<typename T>
const T Gcd(const T& a, const T& b) {
    return gcd(a, b);
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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(2 * n);
    for (int i = 0; i < n; i++) {
        b[i] = b[i + n] = a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a.back()) {
        cout << 0 << endl;
        return;
    }
    sparseTable<int, Gcd> g(b);
    auto go = [&](int mid) {
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            t[i] = g.query(i, i + mid - 1);
        }
        for (int i = 0; i < n; i++) {
            if (t[i] != t[0]) return false;
        }
        return true;
        };
    int L = 1, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) ? R = mid : L = mid + 1;
    }
    cout << L - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}