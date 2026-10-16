#include <bits/stdc++.h>
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
    int q;
    cin >> q;
    set<int> s;
    vector<pair<int, int>> Q;
    vector<int> d;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            Q.push_back({ 1, x });
            auto it1 = s.upper_bound(x);
            if (it1 != s.begin()) {
                it1--;
                d.push_back(x - *it1);
            }
            auto it2 = s.upper_bound(x);
            if (it2 != s.end()) {
                d.push_back(*it2 - x);
            }
            s.insert(x);
        }
        else if (t == 2) {
            int k;
            cin >> k;
            Q.push_back({ 2, k });
            d.push_back(k);
            d.push_back(k + 1);
        }
        else {
            assert(false);
        }
    }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    s.clear();
    auto id = [&](int X) {
        return lower_bound(d.begin(), d.end(), X) - d.begin() + 1;
        };
    int z = d.size();
    fenwick<int> fen(z);
    for (int i = 0; i < q; i++) {
        if (Q[i].first == 1) {
            int x = Q[i].second;
            auto it1 = s.upper_bound(x);
            if (it1 != s.begin()) {
                int D = x - *prev(it1);
                int j = id(D);
                fen.add(j, 1);
            }
            auto it2 = s.upper_bound(x);
            if (it2 != s.end()) {
                int D = *it2 - x;
                int j = id(D);
                fen.add(j, 1);
            }
            if (it1 != s.begin() && it2 != s.end()) {
                --it1;
                int D = *it2 - *it1;
                int j = id(D);
                fen.add(j, -1);
            }
            s.insert(x);
        }
        else {
            if (s.empty()) {
                cout << 0 << endl;
            }
            else {
                int k = Q[i].second;
                int j = id(k);
                cout << fen.rangeQuery(j + 1, z) + 1 << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

