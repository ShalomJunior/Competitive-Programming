#include<bits/stdc++.h>
using namespace std;

set<char> in = { 'a', 'e', 'i', 'o', 'u', 'y' };
void solve(string line) {
    istringstream iss(line);
    int tot = 0;
    int cnt = 0;
    string w;
    while (iss >> w) {
        tot++;
        for (auto& c : w) {
            if (in.count(c)) cnt++;
        }
    }
    if (cnt == 2 * tot) {
        cout << "NP";
    }
    else {
        cout << "P";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    while (getline(cin, line)) solve(line);
}