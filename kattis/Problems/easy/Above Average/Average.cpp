#include <bits/stdc++.h>
#define db double

using namespace std;

void solve() {
    int n; cin >> n;
    vector<db> v(n);
    for (auto& c : v) cin >> c;

    int nb = 0;
    db mean = (db)accumulate(v.begin(), v.end(), 0) / n;
    for (auto& c : v)
        if (c > mean)nb++;

    printf("%.3f", (db)nb / n * 100);
    cout << "%" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}