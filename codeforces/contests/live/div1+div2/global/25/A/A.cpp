#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 2) {
        cout << (s == "00" ? "YES" : "NO");
    }
    else {
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') idx.push_back(i);
        }
        int m = idx.size();
        if (m & 1 || (m == 2 && idx[0] + 1 == idx[1])) {
            cout << "NO";
        }
        else cout << "YES";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}