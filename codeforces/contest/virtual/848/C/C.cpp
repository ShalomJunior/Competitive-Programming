#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;

    set<char> s(a.begin(), a.end());

    vector<char> let(s.begin(), s.end());
    vector<int> idx(let.size());

    if (let.size() >= k)
        fill(idx.end() - k, idx.end(), 1);
    else
        fill(idx.begin(), idx.end(), 1);

    ll ans = 0;
    do {
        unordered_set<char> q;
        for (int i = 0; i < let.size(); i++) {
            if (idx[i])q.insert(let[i]);
        }
        string temp = a;
        for (int i = 0; i < n; i++) {
            if (b[i] != temp[i] && q.count(temp[i])) {
                temp[i] = b[i];
            }
        }
        ll curr = 0;
        for (int i = 0; i < n; i++) {
            ll pos = -1;
            while (i + pos + 1 < n && temp[i + pos + 1] == b[i + pos + 1])
                pos++;

            pos++;
            curr += pos * (pos + 1) / 2;
            i += pos;
        }
        ans = max(ans, curr);

    } while (next_permutation(idx.begin(), idx.end()));

    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}