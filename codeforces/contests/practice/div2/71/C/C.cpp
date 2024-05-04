#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
template<typename T>
const T Max(const T& a, const T& b) {
    return max(a, b);
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
    string w; cin >> w;
    int n = w.length();
    int m; cin >> m;
    vector<string> a(m);
    for (auto& s : a)cin >> s;
    vector<int> b(n, -INF);
    for (int j = 0; j < m; j++) {
        string s = a[j];
        int len = s.length();
        for (int i = 0; i + len - 1 < n; i++) {
            if (w.substr(i, len) == s) {
                b[i + len - 1] = max(b[i + len - 1], i);
            }
        }
    }
    sparseTable<int, Max> g(b);
    int len = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        int L = 0, R = i;
        while (L < R) {
            int mid = (L + R) / 2;
            g.query(mid, i) < mid ? R = mid : L = mid + 1;
        }
        if (g.query(R, i) < R) {
            int z = i - R + 1;
            if (z > len) {
                len = z;
                j = i - z + 1;
            }
        }
    }
    cout << len << " " << j << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}