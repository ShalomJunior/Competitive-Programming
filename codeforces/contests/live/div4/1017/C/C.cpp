#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= 2 * n; i++) s.insert(i);
    vector<int> p(2 * n + 5);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> p[i + j];
            s.erase(p[i + j]);
        }
    }
    p[1] = *s.begin();
    for (int i = 1; i <= 2 * n; i++) cout << p[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
