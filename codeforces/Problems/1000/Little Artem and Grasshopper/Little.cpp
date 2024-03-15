#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> v(n);
    for (auto& c : v)
        cin >> c;

    int pos = 0;
    int cnt = 0;
    while (cnt++ < n) {
        pos += (s[pos] == '>') ? v[pos] : -v[pos];
        if (pos< 0 || pos > n - 1) {
            cout << "FINITE" << endl;
            return 0;
        }
    }

    cout << "INFINITE" << endl;
}