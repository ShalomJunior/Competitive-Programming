#include <bits/stdc++.h>

using namespace std;

void solve() {
    string line; cin >> line;
    int sm = 0;
    bool zero = false;
    int even = 0;
    for (auto& c : line) {
        zero |= (c == '0');
        sm += (c - '0');
        even += (c - '0') % 2 == 0;
    }

    if (sm % 3 == 0 && zero && even > 1)
        cout << "red" << endl;
    else
        cout << "cyan" << endl;
}


int main() {
    int n; cin >> n;
    while (n--)solve();
}