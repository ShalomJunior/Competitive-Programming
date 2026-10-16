#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
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
    int n;
    cin >> n;
    vector<int> a(n);
    fenwick<int> fen(n + 1);
    for (auto& c : a) {
        cin >> c;
        fen.add(c + 1, 1);
    }
    int mex = 0;
    while (fen.rangeQuery(mex + 1, mex + 1)) mex++;
    multiset<int> in, out;
    vector<pair<int, int>> p(mex + 1, { INF, 0 });
    for (int i = 0; i <= mex; i++) {
        p[i].first = fen.rangeQuery(i + 1, i + 1);
        p[i].second = n - i;
        in.insert(p[i].first);
        out.insert(p[i].second);
    }
    int ans = 0;
    for (int k = 0; k <= n; k++) {
        while (!in.empty() && *in.begin() == k) {
            in.erase(in.begin());
            ans++;
        }
        cout << ans << " ";
        while (!out.empty() && *out.begin() == k) {
            out.erase(out.begin());
            ans--;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
