#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    int ans = 0;
    stringstream out;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                ans++;
                out << "C";
            }
            else {
                out << ".";
            }
        }
        out << endl;
    }

    cout << ans << endl;
    cout << out.str() << endl;
}