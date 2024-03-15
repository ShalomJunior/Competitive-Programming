#include <bits/stdc++.h>

using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<set<int>> base;
void generate_combinations(vector<int> &v, int n, int k, vector<int> &combination, vector<vector<int>> &combinations)
{
    if (combination.size() == k)
    {
        combinations.push_back(combination);
        return;
    }
    for (int i = n; i < v.size(); i++)
    {
        combination.push_back(v[i]);
        generate_combinations(v, i + 1, k, combination, combinations);
        combination.pop_back();
    }
}

vector<vector<int>> get_combinations(vector<int> &v)
{
    vector<vector<int>> all_combinations;
    for (int k = 1; k <= v.size(); k++)
    {
        vector<vector<int>> combinations;
        vector<int> combination;
        generate_combinations(v, 0, k, combination, combinations);
        all_combinations.insert(all_combinations.end(), combinations.begin(), combinations.end());
    }
    return all_combinations;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    base.resize(m);
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int s;
            cin >> s;
            base[i].insert(s);
        }
    }

    vector<int> pr(m);

    for (int i = 0; i < m; i++)
        pr[i] = i;

    vector<vector<int>> all = get_combinations(pr);

    int count = 0;
    for (auto &perm : all)
    {
        set<int> t;
        for (auto &v : perm)
        {
            t.insert(base[v].begin(), base[v].end());
            if (t.size() == n)
            {
                count++;
                break;
            }
        }
    }

    cout << count << endl;
    return 0;
}
