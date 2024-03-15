#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<char>let;
    for (char c = 'a'; c <= 'z'; c++) let.insert(c);
    string ans;
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            ans += *let.begin();
            let.erase(let.begin());
        }
        else {
            for (char c = 'a'; c <= 'z'; c++) {
                if (cnt[c] == a[i]) {
                    ans += c;
                    break;
                }
            }
        }
        cnt[ans.back()]++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
