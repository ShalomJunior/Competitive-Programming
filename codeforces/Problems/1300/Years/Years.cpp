#include <bits/stdc++.h>
#define ll long long
#define F first 
#define S second 

using namespace std;

int main() {
    int n; cin >> n;
    ll p = 0, y = 0;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        ll b, d; cin >> b >> d;
        v[i].F = b; v[i].S = d;
    }

    sort(v.begin(), v.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        ll b = v[i].F, d = v[i].S;
        while (!pq.empty() && pq.top() <= b) {
            pq.pop();
        }
        pq.push(d);
        if (p < pq.size()) {
            p = pq.size();
            y = b;
        }
    }
    cout << y << " " << p << endl;
}