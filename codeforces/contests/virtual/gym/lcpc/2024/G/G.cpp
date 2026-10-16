#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int x = count(s.begin(), s.end(), 'm');
    int y = count(s.begin(), s.end(), 'y');
    if (x < y) {
        cout << "Yassin";
    }
    else if (x == y) {
        cout << "Draw";
    }
    else {
        cout << "Mostafa";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}