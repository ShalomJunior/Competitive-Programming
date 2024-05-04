#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int nb = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 0) break;
        if (i < k) nb++;
        else if (v[i] == v[k - 1]) nb++;
        else  break;
    }
    cout << nb << endl;
}