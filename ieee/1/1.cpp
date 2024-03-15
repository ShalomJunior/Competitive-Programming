#include <bits/stdc++.h>
using namespace std;

const int N = 26;
vector<char> h;
void solve() {
    int shift; cin >> shift;
    cin.ignore();
    string line; getline(cin, line);
    int n = line.size();
    string ans;
    if (line.find(" the ") == -1) {
        for (int i = 0; i < n; i++) {
            if (line[i] == ' ')  ans += ' ';
            else {
                int start = line[i] - 'a';
                start += shift;
                ans += h[start];
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (line[i] == ' ')  ans += ' ';
            else {
                int start = line[i] - 'a' + N;
                start -= shift;
                ans += h[start];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 2 * N; i++) {
        h.push_back('a' + i % N);
    }
    int t; cin >> t;
    while (t--) solve();
}