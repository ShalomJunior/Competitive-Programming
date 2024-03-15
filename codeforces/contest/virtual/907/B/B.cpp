#include <bits/stdc++.h>
using namespace std;

const int N = 32;
void solve() {
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> b(N);
    for (int i = 0; i < q; i++) {
        int c; cin >> c;
        b[c].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        int query = -1;
        while (query < q) {
            int j;
            for (j = N - 1; j > 0; j--) {
                int d = 1 << j;
                if (a[i] % d == 0) break;
            }
            if (j == 0) break;
            int last = q, id;
            for (int k = 1; k <= j; k++) {
                auto it = upper_bound(b[k].begin(), b[k].end(), query);
                if (it != b[k].end() && *it < last) {
                    last = *it;
                    id = k;
                }
            }
            if (last == q) break;
            a[i] += (1 << (id - 1));
            query = last;
        }
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}