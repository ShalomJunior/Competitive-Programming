#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    unordered_set<ll> s;
    for (auto& c : a) {
        cin >> c;
        s.insert(c);
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (i && a[i - 1] == a[i])continue;
        int j = i + 1, k = n - 1;
        while (j < k) {

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}