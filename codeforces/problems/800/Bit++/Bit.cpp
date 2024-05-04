#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int sm = 0;
    while (n--) {
        string str; cin >> str;
        if (str.find('+') != string::npos) sm++;
        else sm--;
    }

    cout << sm << endl;
}