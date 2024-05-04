#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans++;
            if (a[i + 1] != b[i + 1]) {
                i++;
            }
        }
    }

    cout << ans << endl;
}