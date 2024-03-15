#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<string> s = { "ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE" };
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string v; cin >> v;
        if (s.find(v) != s.end())ans++;
        else {
            try {
                int val = stoi(v);
                if (val < 18)ans++;
            }
            catch (const exception& e) {}
        }
    }
    cout << ans << endl;
}