#include<bits/stdc++.h>
#define ll long long

using namespace std;

void out(set<ll>& a) {
    cout << a.size() << endl;
    for (auto it = a.begin(); it != a.end();it++)
        cout << *it << " ";
    cout << endl;
}

int main() {
    ll n; cin >> n;
    if (1 & n * (n + 1) / 2) {
        cout << "NO" << endl;
        return 0;
    }

    set<ll> a, b;
    for (ll i = 1; i <= n;i++)
        a.insert(i);

    ll tar = n * (n + 1) / 4;
    ll sma = 0, smb = 0;
    while (smb < tar) {
        ll diff = tar - smb;
        if (a.find(diff) != a.end()) {
            b.insert(diff);
            a.erase(diff);
            smb += diff;
        }
        else {
            ll mx = *prev(a.end());
            b.insert(mx);
            a.erase(mx);
            smb += mx;
        }
    }
    cout << "YES" << endl;
    out(a);
    out(b);
}