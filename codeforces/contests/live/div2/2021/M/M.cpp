#include <bits/stdc++.h>
using namespace std;

const int N = 10;
map<int, int> h;
void init() {
    h[0] = 0;
    for (int i = 1; i < 5000; i++) {
        int res = i ^ (i << 1);
        //int j = N;
        //while ((res & (1 << j)) == 0) j--;
        //h[res - (1 << j)] = i;
        h[res] = i;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << h[x] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();
}
