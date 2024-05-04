#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        v[i] = c;
    }

    int occu = 0;
    int free = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            if (free > 0) free--;
            else occu++;
        }
        else {
            if (occu > 2) occu -= 2;
        }
    }

    cout << occu << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}