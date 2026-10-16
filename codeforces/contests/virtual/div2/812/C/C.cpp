#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
set<int> s;

void solve() {
    int n;
    cin >> n;
    set<int> ids;
    for (int i = 0; i < n; i++) ids.insert(i);
    vector<int> p(n);
    for (int i = n - 1; i >= 0; i--) {
        for (auto it = s.lower_bound(i + *prev(ids.end())); ; it--) {
            int need = *it - i;
            if (ids.count(need)) {
                p[i] = need;
                ids.erase(need);
                break;
            }
        }
    }
    for (auto& c : p) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i * i < N; i++) s.insert(i * i);
    int t; cin >> t;
    while (t--)solve();
}