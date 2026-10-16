#include <bits/stdc++.h>
using namespace std;

const int N = 3;
const int M = 10;
void solve() {
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int j = 0;
        while (j < M && s[j] != '=') j++;
        if (j < M) {
            j++;
            while (j < M && s[j] == '.') j++;
            if (j == M) {
                cout << "You shall pass!!!";
            }
            else {
                cout << s[j];
            }
            cout << endl;
            return;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
