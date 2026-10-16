#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
const int M = 5;
void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    string p;
    for (int i = 0; i < N; i++) p += to_string(n);
    stringstream ss;
    for (int a = 1; a * n <= N; a++) {
        int r = n - a * n;
        for (int len = 1; len <= M; len++) {
            int s = stoi(p.substr(0, len));
            if (s == r) {

            }
        }
    }
    cout << cnt << endl;
    cout << ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}