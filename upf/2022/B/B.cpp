#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; getline(cin, str);
    for (auto& c : str) c = tolower(c);
    unordered_map<char, int> mp;
    for (auto& c : str) {
        if (c >= 'a' && c <= 'z')mp[c]++;
    }

    cout << "texte " << ((mp.size() == 26) ? "parfait" : "imparfait") << endl;
}