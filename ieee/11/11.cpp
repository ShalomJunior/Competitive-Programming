#include <bits/stdc++.h>
using namespace std;

map<char, int> p;

void read(deque<char>& dq) {
    string line; getline(cin, line);
    istringstream is(line);
    char c;
    while (is >> c) dq.push_back(c);
}

void solve() {
    deque<char> f, s;
    read(f), read(s);
    int M = 1e6;
    int streak = 0;
    while (M-- && !f.empty() && !s.empty()) {
        int x = f.front(), y = s.front();
        if (x == y) {
            f.push_back(x); s.push_back(y);
            f.pop_front(); s.pop_front();
            streak++;
        }
        else if (p[x] < p[y]) {
            s.pop_front(); s.push_back(x);
            f.pop_front();
            streak = 0;
        }
        else {
            f.pop_front(); f.push_back(y);
            s.pop_front();
            streak = 0;
        }
    }
    if (streak > 1000) cout << "draw";
    else if (f.empty()) cout << "player 2";
    else cout << "player 1";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string card = "23456789TJQKA";
    for (int i = 0; i < card.size(); i++) {
        p[card[i]] = i;
    }
    int t; cin >> t;
    cin.ignore();
    while (t--) solve();
}
