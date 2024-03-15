#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n; cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
        return;
    }
    stack<ll> q;
    while (n > 1) {
        ll curr = n / 2;
        if (curr & 1) {
            q.push(2);
            n = curr;
        }
        else {
            q.push(1);
            n = curr + 1;
        }
    }
    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}