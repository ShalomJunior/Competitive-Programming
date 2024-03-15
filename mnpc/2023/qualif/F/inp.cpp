#include <bits/stdc++.h>
using namespace std;

const int T = 50;
const int N = 40;
const long long S = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    cout << T << endl;
    for (int i = 0; i < T; i++) {
        cout << N << " " << rand() % S << endl;
        for (int j = 0; j < N; j++) {
            cout << 53 << " " << rand() % 30 + 1 << endl;
        }
    }
}