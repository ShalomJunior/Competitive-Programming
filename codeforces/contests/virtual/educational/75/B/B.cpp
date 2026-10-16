#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a = 0;
    int b = 0;
    vector<int> z;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int len = s.length();
        z.push_back(len % 2);
        a += count(s.begin(), s.end(), '0');
        b += count(s.begin(), s.end(), '1');
    }
    for (int i = 0; i < n; i++) {
        if (z[i]) {
            if (a & 1) a--;
            else if (b & 1) b--;
            else {
                if (a > 0) a--;
                else if (b > 0) b--;
                else assert(false);
            }
        }
    }
    cout << (a % 2 == 0 && b % 2 == 0 ? n : n - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
