#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int sa = accumulate(a.begin(), a.end(), 0);
    int sb = accumulate(b.begin(), b.end(), 0);
    if (sa != sb) {
        cout << -1 << endl;
        return;
    }
    int j = (a[0] > b[0] ? a[0] : a[1]);
    int k = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) k += b[i] - a[i];
        else {
            for (int j = 0; j < a[i] - b[i]; j++) q.push(i);
        }
    }
    cout << k << endl;
    for (int i = 0; i < n; i++) {
        while (a[i] < b[i]) {
            cout << q.front() + 1 << " " << i + 1 << endl;
            a[i]++;
            q.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}