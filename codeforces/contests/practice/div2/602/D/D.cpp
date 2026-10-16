#include<bits/stdc++.h>
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

struct Query {
    int id;
    int k;
    int pos;
    bool operator<(const Query& o) const {
        if (k != o.k) return k < o.k;
        if (pos != o.pos) return pos < o.pos;
        return id < o.id;
    }
};

void solve() {
    int n;
    cin >> n;
    map<int, deque<int>>  h;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h[x].push_back(i);
        a[i] = b[i] = x;
    }
    int m;
    cin >> m;
    vector<Query> Q(m);
    for (int i = 0; i < m; i++) {
        cin >> Q[i].k >> Q[i].pos;
        Q[i].id = i;
    }
    sort(b.begin(), b.end());
    sort(Q.begin(), Q.end());
    fenwick<int> fen(n);
    vector<int> ans(m);
    int j = n - 1;
    for (auto& [id, k, pos] : Q) {
        while (j >= n - k) {
            int u = h[b[j]].front();
            h[b[j]].pop_front();
            fen.add(u + 1, 1);
            j--;
        }
        int L = 0, R = n - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            if (fen.query(mid + 1) < pos) {
                L = mid + 1;
            }
            else {
                R = mid;
            }
        }
        ans[id] = a[L];
    }
    for (auto& c : ans) cout << c << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
