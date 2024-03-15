#include <bits/stdc++.h>
#define Mine pair<int, int>
#define F first
#define S second 
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
    int n; cin >> n;
    vector<int> x(n);
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        p[i].F = x[i];
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        p[i].S = v[i];
    }
    sort(p.begin(), p.end());
    auto rv = v;
    sort(rv.begin(), rv.end());
    rv.resize(unique(rv.begin(), rv.end()) - rv.begin());
    int m = rv.size();
    fenwick<long long> fen(m);
    fenwick<int> cnt(m);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(rv.begin(), rv.end(), p[i].S) - rv.begin() + 1;
        int nb = cnt.query(j);
        long long s = fen.query(j);
        ans += 1LL * nb * p[i].F - s;
        fen.add(j, p[i].F);
        cnt.add(j, 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}