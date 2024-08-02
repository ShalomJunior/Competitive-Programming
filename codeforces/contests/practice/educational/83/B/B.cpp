#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(3);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int cnt = 3;
    while (cnt) {
        bool done = false;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] > a[0]) {
                a.push_back(a[i] - a[0]);
                a[i] = a[0];
                cnt--;
                done = true;
                break;
            }
        }
        if (!done) break;
        sort(a.begin(), a.end());
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != a[0]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
