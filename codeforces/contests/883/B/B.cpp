#include <bits/stdc++.h>
using namespace std;

const int N = 3;
void solve() {
    vector<string> vec(N);
    for (auto& s : vec)cin >> s;
    for (int i = 0; i < N; i++) {
        bool b = true;
        for (int j = 1; j < N; j++) {
            b &= vec[i][j] == vec[i][0];
        }
        if (b && vec[i][0] != '.') { cout << vec[i][0] << endl; return; }
    }
    for (int j = 0; j < N; j++) {
        bool b = true;
        for (int i = 1; i < N; i++) {
            b &= vec[i][j] == vec[0][j];
        }
        if (b && vec[0][j] != '.') { cout << vec[0][j] << endl; return; }
    }
    bool b = true;
    for (int i = 0; i < N; i++) {
        b &= vec[0][0] == vec[i][i];
    }
    if (b && vec[0][0] != '.') { cout << vec[0][0] << endl; return; }
    b = true;
    for (int i = 0; i < N; i++) {
        b &= vec[i][N - 1 - i] == vec[0][N - 1];
    }
    if (b && vec[0][N - 1] != '.') { cout << vec[0][N - 1] << endl; return; }

    cout << "DRAW" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}