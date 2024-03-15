#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    queue<ll> q;
    q.push(0); q.push(1);
    ll sm = 1;
    for (ll i = 2; i <= n; i++) {
        ll num = q.front() + q.back();
        num %= MOD;
        q.push(num);
        q.pop();
    }
    cout << q.back() << endl;
}