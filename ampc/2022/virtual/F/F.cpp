#include <bits/stdc++.h>
using namespace std;

string f(int n) {
    if (n > 9) return to_string(n);
    return "0" + to_string(n);
}

int main() {
    char c; int hs, ms, ss, he, me, se;
    cin >> hs >> c >> ms >> c >> ss >> c >> he >> c >> me >> c >> se >> c;
    int start = 3600 * hs + 60 * ms + ss;
    int end = 3600 * he + 60 * me + se;
    int diff = end - start;
    if (!diff) { cout << "now" << endl; return 0; }
    int h = diff / 3600; diff %= 3600;
    int m = diff / 60; diff %= 60;
    int s = diff;
    cout << f(h) << "h" << f(m) << "m" << f(s) << "s" << endl;
}