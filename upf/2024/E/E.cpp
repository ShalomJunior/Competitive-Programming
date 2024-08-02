#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5;
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
    vector<vector<int>> s(N), e(N);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        s[l].push_back(r);
        e[r].push_back(l);
    }
    fenwick<int> fen(N);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        fen.add(i, s[i].size());
        for (auto& c : e[i]) {
            cerr << "i = " << i << endl;
            cerr << "c " << c << endl;
            ans += fen.rangeQuery(c, i) - 1;
        }
        cerr << "ans = " << ans << endl;
        for (auto& c : e[i]) {
            cerr << "end =" << c << endl;
            fen.add(c, -1);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}