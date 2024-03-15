#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    for (int x = 0, i = n - 1; i >= 0; i--) {
        if (b[i]) {
            if (!x) { cout << "NO" << endl; return; }
        }
        else x = 1;
    }
    cout << "YES" << endl;
    vector<int> ans;
    for (int i = n - 1; i >= 0; ) {
        int j = i, zeros = 0, ones = 0;
        while (j >= 0 && !b[j]) zeros++, j--;
        while (j >= 0 && b[j]) ones++, j--;
        for (int k = 1; k < zeros + ones; k++) cout << "0 ";
        cout << (ones ? ones : 0) << " ";
        i = j;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}