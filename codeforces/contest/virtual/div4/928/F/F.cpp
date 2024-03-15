#include <bits/stdc++.h>
using namespace std;

const int N = 7;
void solve() {
    vector<vector<char>> a(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++)a[i][j] = s[j];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}