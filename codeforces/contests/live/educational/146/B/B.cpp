#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll a, b; cin >> a >> b;
    if (a > b)swap(a, b);

    ll k = sqrt(a);
    //Need to grow up to 
    ll ans = k - 1;

    //Curr size
    ll sz = k;
    if (a % k == 0) {
        ans += a / k;
    }
    else {
        ans += a / k - 1;
        sz += a % k;
        ans += 1 + a % k;
    }

    k = sqrt(b);
    if (sz > k) {
        if (b % sz == 0) {
            ans += b / k;
        }
        else {
            ans += b / k - 1;
            ans += 1 + b % k;
        }

        cout << "ans = " << ans << endl;
        return;
    }
    else if (sz < k) {
        ans += k - sz;
        sz = k;
    }

    if (b % k == 0) {
        cout << "ans 1= " << ans << endl;
        cout << b << " " << k << endl;
        ans += b / k;
        cout << "ans 1= " << ans << endl;
    }
    else {
        ans += b / k - 1;
        cout << "ans = " << ans << endl;
        ans += 1 + b % k;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}