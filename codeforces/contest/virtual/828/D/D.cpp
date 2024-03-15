#include <bits/stdc++.h>
using namespace std;


int big(int n) {
    int ans = 0;
    while (n % 2 == 0) {
        ans++; n /= 2;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);

    int curr = 0;
    priority_queue<int>pq;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        curr += big(v[i]);
        pq.push(big(i + 1));
    }

    int op = 0;
    while (curr < n && !pq.empty()) {
        curr += pq.top(); pq.pop();
        op++;
    }

    cout << ((curr < n) ? -1 : op) << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}