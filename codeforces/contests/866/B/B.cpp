#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s; cin >> s;
    ll n = s.length();
    s += s.substr(0, n - 1);
    ll idx = 0, l = 0;
    ll cp = 0, cl = 0;
    for (ll i = 0; i < (ll)s.size(); i++) {
        if (s[i] == '1') { cl++; }
        else {
            if (cl > l) {
                idx = cp;
                l = cl;
            }
            cp = i + 1;
            cl = 0;
        }
    }
    l = max(l, cl);
    ll area = 0;
    for (ll i = 1; i <= l; i++) {
        ll temp = i * (l - i + 1);
        area = max(area, temp);
    }
    cout << area << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}