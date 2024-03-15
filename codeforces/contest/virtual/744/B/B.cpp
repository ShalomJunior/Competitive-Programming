
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int cnt = 0;
    stringstream ss;
    for (int i = 0; i < n; i++) {
        int pos = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[pos]) pos = j;
        }
        if (pos == i) continue;
        cnt++;
        ss << i + 1 << " " << pos + 1 << " " << pos - i << endl;
        vector<int> t = a;
        for (int j = i; j <= pos; j++) {
            t[j] = (j == i ? a[pos] : a[j - 1]);
        }
        a = t;
    }
    cout << cnt << endl;
    cout << ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}