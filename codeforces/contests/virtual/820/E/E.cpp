#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ask(ll a, ll b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    ll ans; cin >> ans;
    return ans;
}

void solve() {
    for (int i = 2; i <= 26; i++) {
        ll f = ask(1, i);
        ll s = ask(i, 1);

        if (f == -1) {
            cout << "! " << i - 1 << endl;
            return;
        }
        else if (f != s) {
            cout << "! " << f + s << endl;
            return;
        }
    }
}

int main() {
    solve();
}