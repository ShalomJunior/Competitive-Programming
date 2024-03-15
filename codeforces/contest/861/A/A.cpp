#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

vector<bool> done(N);
vector<int> luc(N);

int luck(int n) {
    if (done[n]) return luc[n];

    vector<int> dig;
    while (n > 0) {
        dig.push_back(n % 10);
        n /= 10;
    }
    sort(dig.begin(), dig.end());
    int ans = dig.back() - dig[0];
    luc[n] = ans; done[n] = true;

    return ans;
}

void solve() {
    int l, r; cin >> l >> r;
    int curr = -1, num = 0;
    for (int i = r; i >= l; i--) {
        int nw = luck(i);
        if (nw == 9) {
            cout << i << endl;
            return;
        }
        else if (nw > curr) {
            curr = nw; num = i;
        }
    }
    cout << num << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}