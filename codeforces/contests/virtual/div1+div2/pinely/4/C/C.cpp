#include<bits/stdc++.h>
using namespace std;

const int N = 40;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int k = 0;
    stringstream ss;
    while (k < N) {
        if (a[n - 1] == 0) break;
        int x = (a[0] + a[n - 1]) / 2;
        for (int i = 0; i < n; i++) {
            a[i] = abs(a[i] - x);
        }
        k++;
        ss << x << " ";
        sort(a.begin(), a.end());
    }
    if (a[n - 1] == 0) {
        cout << k << endl;
        cout << ss.str() << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}

