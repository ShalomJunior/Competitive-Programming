#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    unordered_set<string> db;
    unordered_set<string> s1, s2, s3;
    for (int i = 0; i < 3 * n; ++i) {
        string s; cin >> s;
        db.insert(s);
        if (i < n) s1.insert(s);
        else if (i < 2 * n) s2.insert(s);
        else s3.insert(s);
    }

    int a1 = 0, a2 = 0, a3 = 0;
    for (auto it = db.begin(); it != db.end(); ++it) {
        int cnt = s1.count(*it) + s2.count(*it) + s3.count(*it);
        bool b1 = s1.count(*it);
        bool b2 = s2.count(*it);
        bool b3 = s3.count(*it);
        if (cnt == 2) {
            if (b1) a1++;
            if (b2) a2++;
            if (b3) a3++;
        }
        else if (cnt == 1) {
            if (b1) a1 += 3;
            if (b2) a2 += 3;
            if (b3) a3 += 3;
        }
    }
    cout << a1 << " " << a2 << " " << a3 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}