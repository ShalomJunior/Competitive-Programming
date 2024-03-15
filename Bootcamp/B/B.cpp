#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; getline(cin, str);
    for (auto& c : str)c = tolower(c);

    set<char> s;
    for (auto& c : str) {
        if (c >= 'a' && c <= 'z')s.insert(c);
    }

    int len = (int)s.size();
    cout << "texte ";
    cout << ((len == 26) ? "parfait" : "imparfait") << endl;
}