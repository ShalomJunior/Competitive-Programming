#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4, M = 0;
    unordered_map<int, int>f;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        f[v]++;
        M = max(M, f[v]);
    }
    if (M >= 3)cout << "Tringa";
    else if (M == 2) cout << "Ronda";
    else cout << "Better luck next time";
    cout << endl;
}