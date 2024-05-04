#include <bits/stdc++.h>
using namespace std;

template<typename T>
const T And(const T& a, const T& b) {
    return a & b;
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
    int q; cin >> q;
    int p = q;
    sparseTable<int, And> g(a);
    while (q--) {
        int l, k; cin >> l >> k; --l;
        if (a[l] < k) {
            cout << -1 << " ";
            continue;
        }
        int L = l, R = n - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            bool b = (g.query(l, mid) >= k);
            if (b) {
                if (L == mid) (g.query(l, R) >= k) ? L = R : R = L;
                else L = mid;
            }
            else R = mid - 1;
        }
        cout << L + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
