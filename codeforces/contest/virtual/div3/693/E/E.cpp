#include <bits/stdc++.h>
#define Mine pair<int, int> 
#define F first
#define S second
#define mp make_pair
using namespace std;

template<typename T>
const T Min(const T& a, const T& b) {
    return min(a, b);
}

template<typename T, const T(*op)(const T&, const T&)>
class SparseTable {
public:
    vector<vector<T>> st;
    SparseTable(vector<T> vals) {
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

vector<int> get(vector<Mine>& a) {
    vector<int> ans;
    for (auto& p : a) ans.push_back(p.S);
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> h(n), w(n);
    map<Mine, int> idx;
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
        idx[{h[i], w[i]}] = i + 1;
    }
    vector<Mine> H(n), W(n);
    for (int i = 0; i < n; i++) {
        H[i].F = h[i], H[i].S = w[i];
        W[i].F = w[i], W[i].S = h[i];
    }
    sort(H.begin(), H.end());
    sort(W.begin(), W.end());
    SparseTable<int, Min> f(get(H));
    SparseTable<int, Min> g(get(W));
    for (int i = 0; i < n; i++) {
        bool done = false;
        for (auto& p : { mp(h[i], w[i]), mp(w[i], h[i]) }) {
            auto it = lower_bound(H.begin(), H.end(), mp(p.F, 0));
            if (it != H.begin()) {
                --it;
                int j = it - H.begin();
                int m = f.query(0, j);
                if (m < p.S) {
                    auto ans = *lower_bound(W.begin(), W.end(), mp(m, 0));
                    cout << idx[{ans.S, ans.F}] << " ";
                    done = true;
                    break;
                }
            }
        }
        if (done) continue;
        for (auto& p : { mp(h[i], w[i]), mp(w[i], h[i]) }) {
            auto it = lower_bound(W.begin(), W.end(), mp(p.F, 0));
            if (it != W.begin()) {
                --it;
                int j = it - W.begin();
                int m = g.query(0, j);
                if (m < p.S) {
                    auto ans = *lower_bound(H.begin(), H.end(), mp(m, 0));
                    cout << idx[mp(ans.S, ans.F)] << " ";
                    done = true;
                    break;
                }
            }
        }
        if (done) continue;
        cout << -1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}