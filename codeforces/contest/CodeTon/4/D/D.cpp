#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n; cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
        return;
    }
    queue<int> q;
    while (n > 1) {
        ll curr = n / 2;
        if (curr & 1) {
            q.push(1);
            n = curr;
        }
        else {
            q.push(2);
            n = curr + 1;
        }
    }
    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}