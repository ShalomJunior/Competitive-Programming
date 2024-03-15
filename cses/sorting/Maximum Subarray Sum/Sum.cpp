#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto& c : v)cin >> c;

    ll best = v[0], curr = v[0];
    for (int i = 1; i < n; i++) {
        curr = max(curr + v[i], v[i]);
        best = max(best, curr);
    }
    cout << best << endl;
}