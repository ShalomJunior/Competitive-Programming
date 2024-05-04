#include <bits/stdc++.h>
using namespace std;

vector<int> help(vector<int>& a, int M) {
    int n = a.size();
    vector<int> ans;
    bool b = false; int idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == M) {
            b = true;
            idx = i - 1;
        }
        if (b)ans.push_back(a[i]);
    }
    ans.push_back(a[idx]); idx--;
    while (idx >= 0 && a[idx] >= a[0]) {
        ans.push_back(a[idx]); idx--;
    }
    for (int i = 0; i <= idx; i++)ans.push_back(a[i]);
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (n == 1) { cout << 1 << endl; return; }
    vector<int> ans;
    if (a[0] != n && a[n - 1] != n) ans = help(a, n);
    else {
        if (a[0] == n) {
            ans = help(a, n - 1);
            if (a[n - 1] == n - 1) {
                vector<int> temp;
                temp.push_back(n - 1);
                for (int i = 0; i < n - 1; i++)temp.push_back(a[i]);
                ans = max(ans, temp);
            }
        }
        else {
            ans = help(a, n);
            vector<int> temp;
            temp.push_back(n);
            for (int i = 0; i < n - 1; i++)temp.push_back(a[i]);
            ans = max(ans, temp);
        }
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}