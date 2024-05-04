#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> v(n);
    for (auto& s : v)cin >> s;
    vector<pair<int, int>> id(n);

    for (int i = 0; i < n; i++) {
        for (char c : v[i]) {
            id[i].F |= (1 << (c - 'a'));
            id[i].S ^= (1 << (c - 'a'));
        }
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if (id[j].F >> i & 1 ^ 1) temp.push_back(id[j].S);
        }

        sort(temp.begin(), temp.end());
        int mask = ((1 << 26) - 1) ^ (1 << i);
        ll curr = 0;
        for (int k = 0; k < (int)temp.size(); k++) {
            auto f = lower_bound(temp.begin(), temp.end(), temp[k] ^ mask);
            auto s = upper_bound(temp.begin(), temp.end(), temp[k] ^ mask);
            curr += (s - f);
        }
        ans += (curr >> 1LL);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}