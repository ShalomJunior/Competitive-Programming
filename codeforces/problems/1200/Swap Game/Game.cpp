#include <bits/stdc++.h>

using namespace std;

/*
2 7 17
7 1 17
17 1 6
6 1 16
16 1 5

15 1 4

11 1 0
1 10
10 0
*/
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v)cin >> c;
    if (v[0] == 0) {
        cout << "Bob" << endl;
        return;
    }

    sort(v.begin(), v.end());
    int part = v[n - 2];


    cout << ((part & 1) ? "Bob" : "Alice") << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}