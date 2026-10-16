#include <bits/stdc++.h>
using namespace std;

const int N = 9;
void solve() {
    string s;
    cin >> s;
    int x = count(s.begin(), s.end(), '2');
    int y = count(s.begin(), s.end(), '3');
    while (x >= 5) {
        x -= 3;
        y += 1;
    }
    int cnt = 0;
    for (auto& c : s) cnt += c - '0';
    int need = (N - cnt % N) % N;
    vector<int> p;
    for (int i = 0; i < x; i++) p.push_back(2);
    for (int i = 0; i < 10 && i < y; i++) p.push_back(6);
    map<int, bool> mp;
    do {
        int z = 0;
        mp[z] = true;
        for (auto& c : p) {
            z += c;
            mp[z % N] = true;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << (mp[need] ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
