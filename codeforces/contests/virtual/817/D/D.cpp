#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L' && n - 1 - i > i) pq.push(n - 1 - 2 * i);
        if (s[i] == 'R' && i > n - 1 - i) pq.push(2 * i - n + 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L')ans += i;
        else ans += n - 1 - i;
    }
    for (int i = 0; i < n; i++) {
        if (!pq.empty())ans += pq.top(), pq.pop();
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}