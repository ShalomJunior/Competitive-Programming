#include<bits/stdc++.h>
using namespace std;

map<int, string> h;
string P = "1689";
const int M = 7;
void init() {
    do {
        for (int i = 0; i < M; i++) {
            int r = i;
            for (auto& c : P) {
                r = (r * 10 + (c - '0')) % M;
            }
            if (r == 0)  h[i] = P;
        }
    } while (next_permutation(P.begin(), P.end()));
}

void solve() {
    string s;
    cin >> s;
    multiset<char> ms(s.begin(), s.end());
    for (auto& c : P) {
        ms.erase(ms.find(c));
    }
    int r = 0;
    string ans;
    for (auto& c : ms) {
        if (c == '0') continue;
        int dig = c - '0';
        ans += c;
        r = (r * 10 + dig) % 7;
    }
    ans += h[r];
    for (auto& c : ms) {
        if (c == '0') ans += '0';
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();
}