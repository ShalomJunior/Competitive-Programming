#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> names(n);
    vector<int> score(n);
    bool tie = false;
    int M = -1, idx = -1;
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        string s; cin >> s;
        int f = 0;
        for (auto& c : s) {
            if (c == 'W')f += 3;
            else if (c == 'D')f++;
        }
        score[i] = f;
        if (f >= M) {
            tie = f == M;
            M = f; idx = i;
        }
    }
    if (tie) { cout << "Tiebreaker" << endl; return 0; }
    cout << names[idx] << endl;
}