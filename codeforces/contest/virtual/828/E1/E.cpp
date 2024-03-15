#include <bits/stdc++.h>
#define ll long long
#define um unordered_map

using namespace std;

const int N = 1e5 + 5;
bitset<N> b;
vector<ll> primes;

void compute() {
    for (ll i = 2; i < N; ++i) b.set(i);

    for (ll i = 2; i < N; i++) {
        if (!b[i])continue;
        for (ll j = i * i; j < N; j += i) b.reset(j);
    }

    for (ll i = 0; i < N; i++) {
        if (b[i]) primes.push_back(i);
    }
}

void div(ll n, um<ll, ll>& d) {
    int i = 0;
    while (n > 1) {
        //If prime stop
        if (b[n]) { d[n]++;break; }

        if (n % primes[i] == 0) {
            d[primes[i]]++; n /= primes[i];
        }
        else { i++; }
    }
}

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;

    um<ll, ll> ab; div(a, ab); div(b, ab);

    for (ll x = a + 1; x <= c; x++) {
        um<ll, ll> temp; div(x, temp);
        ll mult = 1;
        for (auto& [k, v] : temp) {
            if (ab[k] < v) {
                mult = mult * pow(k, (v - ab[k]));
            }
        }
        ll y = mult * a * b / x;
        if (y > d) continue;
        y *= (d / y);
        if (y > b) {
            cout << x << " " << y << endl;
            return;
        }
    }
    cout << "-1 -1" << endl;
}

int main() {
    compute();
    int t; cin >> t;
    while (t--)solve();
}