#include <bits/stdc++.h>
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

struct query {
    int t;
    int c;
    string title;
    string low;
    string high;
};

void solve() {
    int n;
    cin >> n;
    vector<string> all;
    vector<query> qs(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            string title;
            int cnt;
            cin >> title >> cnt;
            qs[i] = { 1, cnt, title, "", "" };
            all.push_back(title);
        }
        else {
            string l, r;
            cin >> l >> r;
            qs[i] = { 2, -1, "", l, r };
            all.push_back(l);
            all.push_back(r);
        }
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int m = all.size();
    fenwick<int> fen(m + 3);
    for (int i = 0; i < n; i++) {
        if (qs[i].t == 1) {
            int j = lower_bound(all.begin(), all.end(), qs[i].title) - all.begin() + 1;
            fen.add(j, qs[i].c);
        }
        else {
            auto l = qs[i].low;
            auto r = qs[i].high;
            if (l > r) swap(l, r);
            int i = lower_bound(all.begin(), all.end(), l) - all.begin() + 1;
            int j = lower_bound(all.begin(), all.end(), r) - all.begin() + 1;
            cout << fen.rangeQuery(i, j) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}