#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v(3);
    for (auto& c : v) cin >> c;
    string s; cin >> s;
    sort(v.begin(), v.end());
    for (auto c : s)
        cout << v[c - 'A'] << " ";
    cout << endl;
}