#include <bits/stdc++.h>
using namespace std;

template<typename T>
const T& Min(const T& a, const T& b) {
    return min(a, b);
}

template<typename T, const T& (*op)(const T&, const T&)>
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
    sparseTable<int, Min> g(a);
    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (g.query(i, mid) == a[i]) {
                if (l == mid) g.query(i, r) == a[i] ? l = r : r = l;
                else l = mid;
            }
            else r = mid - 1;
        }
        R[i] = l - i;
    }
    vector<int> L(n);
    for (int i = 0; i < n; i++) {
        int l = 0, r = i;
        while (l < r) {
            int mid = (l + r) / 2;
            g.query(mid, i) == a[i] ? r = mid : l = mid + 1;
        }
        L[i] = i - r;
    }
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        h[a[i]] = max(h[a[i]], L[i] + R[i] + 1);
    }
    sort(a.rbegin(), a.rend());
    int i = 0;
    for (int k = 1; k <= n; k++) {
        while (h[a[i]] < k) i++;
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
