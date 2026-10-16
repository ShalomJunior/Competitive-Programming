#include <bits/stdc++.h>
using namespace std;

const int N = 5;
template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < (int)arr.size(); index += (index & (-index))) {
            arr[index] = max(arr[index], val);
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum = max(sum, arr[index]);
        }
        return sum;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector<int> L(n + 1);
    for (int i = 1, id = 1, mx = 0; i <= n; i++) {
        if (h[i] > mx) {
            mx = h[i];
            id = i;
        }
        L[i] = id;
    }
    fenwick<int> fen(n);
    vector<int> R(n + 1);
    for (int i = n; i > 0; i--) {
        R[i] = max(i, fen.query(h[i] - 1));
        fen.add(h[i], i);
    }
    int H = *max_element(h.begin() + 1, h.end());
    int j = 1;
    while (h[j] != H) j++;
    vector<int> ans(n + 1, -1);
    auto f = [&](int id) {
        return id < j ? h[id] : H;
        };
    for (int i = 1; i <= n; i++) {
        int id = i;
        set<int> all;
        while (!all.count(id) && ans[id] == -1) {
            all.insert(id);
            id = R[id];
            all.insert(id);
            ans[i] = max({ ans[i], ans[id], f(id) });
            id = L[id];
            ans[i] = max({ ans[i], ans[id], f(id) });
        }
        for (auto& c : all) ans[c] = ans[i];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
