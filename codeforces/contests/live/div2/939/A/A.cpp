#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, q;
    cin >> k >> q;
    vector<int> a(k);
    for (auto& c : a) cin >> c;
    while (q--) {
        int n; cin >> n;
        vector<int> x(n);
        iota(x.begin(), x.end(), 0);
        bool flag = false;
        do {
            flag = false;
            vector<int> temp;
            for (int i = 0; i < x.size(); i++) {
                if (binary_search(a.begin(), a.end(), i + 1)) {
                    flag = true;
                }
                else {
                    temp.push_back(x[i]);
                }
            }
            assert(!x.empty() || flag == false);
            x = temp;
        } while (flag);
        cout << x.size() << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int T = 250;
    // cout << T << endl;
    // for (int i = 0; i < T; i++) {
    //     int k = 1;
    //     int q = 100;
    //     cout << k << " " << q << endl;
    //     cout << 1 << endl;
    //     for (int j = 0; j < q; j++) {
    //         cout << 100 << " ";
    //     }
    //     cout << endl;
    // }
    int t; cin >> t;
    while (t--)solve();
}
