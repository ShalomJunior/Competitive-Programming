#include <bits/stdc++.h>
using namespace std;

const int N = 100;
void solve() {
    int n; cin >> n;
    vector<int> a(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    for (int i = 0; i < N - 1; i++) {
        if (a[i] < a[i + 1]) { cout << "NO" << endl; return; }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}