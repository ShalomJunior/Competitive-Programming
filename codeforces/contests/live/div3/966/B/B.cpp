#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    deque<int> dq;
    dq.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] == dq.front() - 1) {
            dq.push_front(a[i]);
        }
        else if (a[i] == dq.back() + 1) {
            dq.push_back(a[i]);
        }
        else {
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
