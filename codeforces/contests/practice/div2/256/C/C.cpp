#include <bits/stdc++.h>
using namespace std;

vector<int> a;
template<typename T>
const T Min(const T& i, const T& j) {
    return a[i] < a[j] ? i : j;
}

template<typename T, const T(*op)(const T&, const T&)>
class sparseTable {
public:
    vector<vector<T>> st;
    sparseTable(vector<T> vals) {
        int n = vals.size();
        int rows = __lg(n) + 1;
        st.resize(rows);
        st[0].resize(n);
        iota(st[0].begin(), st[0].end(), 0);
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

int go(int l, int r, int h, sparseTable<int, Min>& g) {
    if (l > r) return 0;
    int m = g.query(l, r);
    int ans = min(r - l + 1, a[m] - h + go(l, m - 1, a[m], g) + go(m + 1, r, a[m], g));
    return ans;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto& c : a) cin >> c;
    sparseTable<int, Min> g(a);
    cout << go(0, n - 1, 0, g) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
