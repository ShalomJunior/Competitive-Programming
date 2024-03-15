#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    vector<set<int>> a(n);
    for (int i = 0; i < n; i++) {
        if (!i) a[i].insert(0);
        if (a[i].size() > 1) {
            cout << "NO" << endl;
            return;
        }
        int c = *a[i].begin();
        for (int j = 0; j < n; j++) {
            if (j < i && s[j] > s[i]) a[j].insert(c ^ 1);
            if (i < j && s[j] < s[i]) a[j].insert(c ^ 1);
            if (a[j].size() > 1) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << *a[i].begin();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}