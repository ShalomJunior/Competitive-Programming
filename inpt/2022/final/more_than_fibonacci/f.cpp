#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    queue<ll> q;
    ll sm = 0;
    q.push(1);
    for (ll i = 2; i <= m; i++) {
        sm += q.back();
        q.push(sm);
    }

    for (ll i = m + 1; i <= n; i++) {
        sm += q.back();
        sm %= MOD;
        q.push(sm);
        sm -= q.front();
        sm += MOD; sm %= MOD;
        q.pop();
    }

    cout << q.back() << endl;
}