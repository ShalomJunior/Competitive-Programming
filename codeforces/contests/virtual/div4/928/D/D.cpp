#include <bits/stdc++.h>
using namespace std;

const int N = 31;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    multiset<int>  groups, use;
    for (int i = 0; i < n; i++) {
        if (use.count(a[i])) {
            use.erase(use.find(a[i]));
        }
        else {
            groups.insert(a[i]);
            int m = 0;
            for (int j = 0; j < N; j++) {
                if (a[i] & (1 << j)) {}
                else m |= (1 << j);
            }
            use.insert(m);
        }
    }
    cout << groups.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}