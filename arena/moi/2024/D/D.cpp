#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<string, int> h;
    for (int i = 0; i < n; i++) {
        string path; cin >> path;
        vector<string> s;
        istringstream is(path);
        string t;
        while (getline(is, t, '/')) {
            s.push_back(t);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
