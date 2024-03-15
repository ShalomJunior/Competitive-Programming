#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;

    vector<ll> v(n);
    for (auto& c : v)
        cin >> c;


    for (auto& c : v) {
        if (c == 1) c++;
    }

    for (int i = 1; i < n; i++) {
        if (v[i] % v[i - 1] == 0) {
            for (ll j = v[i]; ; j++) {
                bool div = false;
                for (int k = 0; k < i; k++) {
                    if (j % v[k] == 0) {
                        div = true; break;
                    }
                }

                if (!div) {
                    v[i] = j; break;
                }
            }
        }
    }

    for (auto& c : v) {
        cout << c << " ";
    }

    cout << endl;
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}