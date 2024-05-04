#include <bits/stdc++.h>
using namespace std;

const int N = 8;
void solve() {
    vector<vector<char>> card(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            card[i].push_back(c);
        }
    }
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (card[i][j] != '#') continue;
            bool good = true;
            for (int n : {-1, 1}) {
                for (int m : {-1, 1}) {
                    if (card[i + n][j + m] != '#') {
                        good = false;
                        break;
                    }
                }
                if (good) { cout << i + 1 << " " << j + 1 << endl; return; }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}