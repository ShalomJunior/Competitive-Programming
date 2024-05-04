#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;
    set<long long> s;
    long long i = 1;
    while (i * i <= n) s.insert(i), i++;
    i = 1;
    while (i * i * i <= n) s.insert(i * i * i), i++;
    cout << s.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}