#include <bits/stdc++.h>

using namespace std;

vector<int> kmp_table(string pattern)
{

    int m = pattern.length();
    vector<int> res(m);
    res[0] = 0;
    int k = 0;
    for (int j = 1; j < m; j++)
    {
        while (k > 0 && pattern[j] != pattern[k])
            k = res[k - 1];

        if (pattern[j] == pattern[k])
            k++;

        res[j] = k;
    }
    return res;
}

int kmp(string word, string pattern)
{
    int n = word.length();
    int m = pattern.length();
    vector<int> res;
    vector<int> table = kmp_table(pattern);

    int k = 0;

    for (int j = 0; j < n; j++)
    {
        while (k > 0 && word[j] != pattern[k])
            k = table[k - 1];

        if (word[j] == pattern[k])
            k++;

        if (k == m)
        {
            res.push_back(j - k + 1);
            k = 0;
        }
    }
    return res.size();
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    cout << kmp(s, "111");
}