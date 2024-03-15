#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int, string>mp;

    int mx = abs(n);
    for (int i = 1; i <= mx; i++) {
        vector<string> add(2 * mx - 1, " ");
        int x = (n > 0) ? i : mx - i + 1;
        add[i - 1] = to_string(x);
        add[2 * mx - 1 - i] = to_string(x);
        stringstream ss;
        for (auto& s : add)ss << s;
        mp[i] = ss.str();
    }

    for (int i = 1; i <= mx; i++)
        cout << mp[i] << endl;

    for (int i = mx - 1; i > 0; i--)
        cout << mp[i] << endl;
}