#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    while (n--) cin >> v[n];
    sort(v.begin(), v.end());
    int mn = INT_MAX;
    for (int i = 1; i < v.size(); i++)
        if (v[i] - v[i - 1] < mn) mn = v[i] - v[i - 1];


    cout << mn << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}