#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<ll>> v(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            v[i].push_back(x);
        }
    }
    v[0][0] = v[0][1] * v[0][2] / v[1][2];
    for (int i = 1; i < n; i++) {
        v[i][i] = v[i][i - 1] * v[i - 1][i] / v[i - 1][i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << (ll)sqrt(v[i][i]) << " ";
    }
    cout << endl;
}