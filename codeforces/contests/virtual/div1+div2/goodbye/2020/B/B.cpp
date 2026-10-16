#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    a[n - 1]++;
    sort(a.begin(), a.end());
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] + 1 < a[i + 1]) {
            a[i]++;
        }
    }
    cout << set<int>(a.begin(), a.end()).size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}