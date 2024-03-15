#include <bits/stdc++.h>
using namespace std;

const int N = 26;
map<int, vector<string>> mp;
void prepare() {
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            for (char c = 'a'; c <= 'z'; c++) {
                int sum = a - 'a' + b - 'a' + c - 'a' + 3;
                string s;
                s.push_back(a);
                s.push_back(b);
                s.push_back(c);
                mp[sum].push_back(s);
            }
        }
    }
    for (auto& [k, v] : mp)sort(v.begin(), v.end());
}

void solve() {
    int n; cin >> n;
    cout << mp[n][0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
