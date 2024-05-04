#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string s, e; cin >> s >> e;
    int dx = s[0] - e[0];
    int dy = s[1] - e[1];

    int mx = max(abs(dx), abs(dy));
    int mn = min(abs(dx), abs(dy));

    char x = (dx < 0) ? 'R' : 'L';
    char y = (dy < 0) ? 'U' : 'D';


    cout << mx << endl;
    int i;
    for (i = 0; i < mn; i++)
        cout << x << y << endl;

    for (; i < mx; i++) {
        cout << ((abs(dx) > mn) ? x : y) << endl;
    }
}