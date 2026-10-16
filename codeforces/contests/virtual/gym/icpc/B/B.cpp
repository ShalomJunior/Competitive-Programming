#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int cnt = 0;
    vector<int> x;
    vector<int> y;
    vector<int> z;
    for (int i = 0; i < n; i++) {
        if (a[i] == '#') {
            if (b[i] == '#') {
                y.push_back(i);
            }
            else {
                x.push_back(i);
            }
        }
        else {
            if (b[i] == '#') {
                z.push_back(i);
            }
            else {
                cnt++;
            }
        }
    }
    if (!x.empty() && !z.empty() && y.empty()) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        string A, B;
        for (auto& c : x) A += '#', B += '.';
        for (auto& c : y) A += '#', B += '#';
        for (auto& c : z) A += '.', B += '#';
        while (cnt--) A += '.', B += '.';
        cout << A << endl;
        cout << B << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
