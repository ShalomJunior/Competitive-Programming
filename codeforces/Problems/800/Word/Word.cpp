#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int lower = 0, upper = 0;
    for (auto& c : s)
        (c <= 'Z') ? upper++ : lower++;

    if (lower >= upper) {
        for (auto& c : s)
            c = tolower(c);
    }
    else {
        for (auto& c : s)
            c = toupper(c);
    }
    cout << s << endl;
}