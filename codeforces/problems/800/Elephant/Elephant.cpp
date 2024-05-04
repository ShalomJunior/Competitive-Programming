#include <bits/stdc++.h>

using namespace std;

int cn(int pat, int& x) {
    int sm = x / pat;
    x %= pat;
    return sm;
}

int main() {
    int x; cin >> x;
    int sm = 0;
    for (int k = 5; k > 0; k--)
        sm += cn(k, x);

    cout << sm << endl;
}