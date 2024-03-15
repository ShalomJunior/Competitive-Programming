#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    set<int> odds;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i && i < n - 1 && a[i] & 1) odds.insert(i);
    }
    long long ans = 0;
    for (int k = 0; k < 10; k++) {
        for (int i = 1; i < n - 1; i++) {
            if (odds.empty()) {
                int m = a[i] / 2;
                ans += m;
                a[i] %= 2;
            }
            else {
                bool b = odds.count(i);
                odds.erase(i);
                vector<int> id;
                for (auto it = odds.begin(); it != odds.end() && a[i] >= 2; it++) {
                    a[*it]++;
                    id.push_back(*it);
                    if (next(it) == odds.end()) {
                        a[0]++;
                    }
                    else {
                        it++;
                        a[*it]++;
                        id.push_back(*it);
                    }
                    a[i] -= 2; ans++;
                }
                ans += a[i] / 2; a[i] %= 2;
                for (auto& c : id) odds.erase(c);
                if (b) odds.insert(i);
            }
        }
    }
    cout << (count(a.begin() + 1, a.end() - 1, 1) ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}