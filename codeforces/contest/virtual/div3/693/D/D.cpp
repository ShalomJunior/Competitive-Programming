#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x & 1 ? b.push_back(x) : a.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long alice = 0, bob = 0;
    for (int i = 0; i < n; i++) {
        int da = a.empty() ? 0 : a.back();
        int db = b.empty() ? 0 : b.back();
        if (i & 1) {
            if (db >= da) {
                bob += db;
                b.pop_back();
            }
            else a.pop_back();
        }
        else {
            if (da >= db) {
                alice += da;
                a.pop_back();
            }
            else b.pop_back();
        }
    }
    if (alice > bob) cout << "Alice";
    else if (alice == bob) cout << "Tie";
    else cout << "Bob";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}