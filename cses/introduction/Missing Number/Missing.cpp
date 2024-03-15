#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.erase(x);
    }
    cout << *s.begin() << endl;
}