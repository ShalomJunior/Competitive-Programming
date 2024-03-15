#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    int A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (i < j) A += x;
            if (i > j) B += x;
        }
    }

    if (A > B) cout << "A" << endl;
    else if (A < B) cout << "B" << endl;
    else cout << "E" << endl;
}