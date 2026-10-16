#include <bits/stdc++.h>
using namespace std;

const string T = "BGR";
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> o = { 0, 1, 2 };
    do {
        string S;
        for (auto& c : o) S += T[c];
        int j = n - 1;
        deque<char> r;
        int a = 0;
        int b = 0;
        while (s[j] != S.back()) {
            s[j] == S[0] ? a++ : b++;
            j--;
        }
        string t;
        while (j >= 0) {
            if (s[j] != S[2])
                t += s[j];
            j--;
        }
        t = string(a, S[0]) + t;
        t += string(b, S[1]);
        int z = t.size();
        int x = 0;
        while (x < z && t[x] == t[0]) x++;
        int y = z - 1;
        while (y >= 0 && t[y] == t[z - 1]) y--;
        if (count(s.begin(), s.end(), t[0]) == x && count(s.begin(), s.end(), t[z - 1]) == z - 1 - y) {
            cout << "YES" << endl;
            return;
        }
    } while (next_permutation(o.begin(), o.end()));
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}