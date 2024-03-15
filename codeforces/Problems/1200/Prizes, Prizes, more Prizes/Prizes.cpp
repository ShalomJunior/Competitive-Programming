#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n; cin >> n;
    vector <ll> v(n);
    for (auto& c : v) cin >> c;

    vector<ll> prizes(5);
    for (auto& c : prizes)cin >> c;

    ll p = 0;
    vector<ll> ans(5);
    for (int i = 0; i < n; i++) {
        p += v[i];
        for (int i = 4; i >= 0; i--) {
            if (p >= prizes[i]) {
                ans[i] += p / prizes[i];
                p %= prizes[i];
            }
        }
    }

    for (auto& c : ans)
        cout << c << " ";
    cout << endl;
    cout << p << endl;
}