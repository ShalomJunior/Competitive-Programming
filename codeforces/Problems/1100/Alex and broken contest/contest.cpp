#include <bits/stdc++.h>

using namespace std;

vector<int> kmp_table(string pattern) {
    int m = pattern.length();
    vector<int> res(m);
    res[0] = 0;

    int k = 0;
    for (int j = 1; j < m; j++) {

        while (k > 0 && pattern[k] != pattern[j])
            k = res[k - 1];

        if (pattern[k] == pattern[j]) k++;

        res[j] = k;
    }
    return res;
}

int kmp(string text, vector<string> patterns) {
    int cn = 0;

    for (auto& pattern : patterns) {
        int n = text.length();
        int m = pattern.length();
        vector<int> table = kmp_table(pattern);

        int k = 0;
        for (int j = 0; j < n; j++) {
            while (k > 0 && pattern[k] != text[j])
                k = table[k - 1];

            if (pattern[k] == text[j]) k++;

            if (k == m)
                cn++, k = table[k - 1];
        }
    }

    return cn;
}

int main() {
    string s; cin >> s;
    vector<string> patterns = { "Danil", "Olya", "Slava", "Ann", "Nikita" };
    int cn = kmp(s, patterns);
    if (cn != 1) cout << "NO\n";
    else cout << "YES\n";
}