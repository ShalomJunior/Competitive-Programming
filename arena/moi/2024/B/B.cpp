#include <bits/stdc++.h>
using namespace std;

set<char> in = { 'a', 'e', 'i', 'o', 'u' };
void solve() {
    string line;
    while (line.empty())
        getline(cin, line);
    int n = line.length();
    cout << line[0];
    for (int i = 1; i < n - 1; i++) {
        cout << line[i];
        if (isspace(line[i - 1]) || isspace(line[i]) ||
            isspace(line[i + 1]) || !in.count(line[i])) {
            continue;
        }
        if (!in.count(line[i - 1]) && !in.count(line[i + 1])) {
            cout << line[i];
        }
    }
    if (n > 1) cout << line[n - 1];
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
