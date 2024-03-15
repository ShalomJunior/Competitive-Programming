#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h1, m1, h2, m2;
    char _;
    cin >> h1 >> _ >> m1 >> h2 >> _ >> m2;
    int start = h1 * 60 + m1;
    int end = h2 * 60 + m2;
    int mid = start + (end - start) / 2;
    int ansh = mid / 60, ansm = mid % 60;
    cout << (ansh < 10 ? "0" : "") + to_string(ansh) << ":";
    cout << (ansm < 10 ? "0" : "") + to_string(ansm) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}