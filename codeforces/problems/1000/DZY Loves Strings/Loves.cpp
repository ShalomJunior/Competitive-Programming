#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();

    int k; cin >> k;

    unordered_map<char, int>h;
    int mx = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        int c; cin >> c;
        mx = max(mx, c);
        h[i] = c;
    }


    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (i + 1) * h[s[i]];

    for (int i = 1; i <= k; i++)
        ans += (n + i) * mx;
    cout << ans << endl;
}