#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, v; cin >> n >> v;

    int cnt = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        for (int k = 0; k < j; k++) {
            int val; cin >> val;
            if (val < v) {
                s.insert(i + 1);
            }
        }
    }

    cout << s.size() << endl;
    if (s.size()) {
        for (auto it = s.begin(); it != s.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}