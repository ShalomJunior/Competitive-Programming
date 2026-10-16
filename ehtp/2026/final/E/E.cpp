#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int m = min_element(a.begin(), a.end()) - a.begin();
    int M = max_element(a.begin(), a.end()) - a.begin();
    bool f = false;
    while (q--) {
        int t, x;
        cin >> t;
        if (t < 4) cin >> x;
        if (t == 1) {}
        else if (t == 2) {
            if (x == 0) f = true;
            else {
                if (x < 0) swap(m, M);
            }
        }
        else if (t == 3) {
            if (x < 0) swap(m, M);
        }
        else {
            cout << (f ? 1 : M + 1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}