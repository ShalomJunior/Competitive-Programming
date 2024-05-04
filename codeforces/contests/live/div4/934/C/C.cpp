#include <bits/stdc++.h>
using namespace std;

const string P = "01:00";
const string S = "12:00";
const string T = "13:00";

int f(string s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

string g(int n) {
    n -= f(S);
    int h = n / 60;
    int m = n % 60;
    string sh = (h < 10 ? "0" : "") + to_string(h);
    string sm = (m < 10 ? "0" : "") + to_string(m);
    string ans = sh + ":" + sm;
    return ans;
}

void solve() {
    string s;
    cin >> s;
    if (f(s) < f(P)) {
        cout << "12:" << s.substr(3, 2) << " AM";
    }
    else if (f(s) < f(S)) {
        cout << s << " " << "AM";
    }
    else if (f(S) <= f(s) && f(s) < f(T)) {
        cout << s << " " << "PM";
    }
    else {
        cout << g(f(s)) << " " << "PM";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}