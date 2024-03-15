#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, links;
    cin >> n >> links;

    vector<vector<int>> cycles;
    vector<vector<int>> hash(n + 1, vector<int>(2));

    for (int i = 0; i < links; i++)
    {
        int a, b;
        cin >> a >> b;

        if (!hash[a][0] && !hash[b][0])
        {
            cycles.push_back({a, b});
            hash[a][0] = 1;
            hash[b][0] = 1;

            hash[a][1] = cycles.size() - 1;
            hash[b][1] = cycles.size() - 1;
        }
        else if (!hash[a][0] && hash[b][0])
        {
            cycles[hash[b][1]].push_back(a);
            hash[a][0] = 1;
            hash[a][1] = hash[b][1];
        }
        else if (hash[a][0] && !hash[b][0])
        {
            cycles[hash[a][1]].push_back(b);
            hash[b][0] = 1;
            hash[b][1] = hash[a][1];
        }
        else
        {
            if (hash[a][1] == hash[b][1])
                continue;

            for (auto v : cycles[hash[b][1]])
            {
                cycles[hash[a][1]].push_back(v);
                hash[v][1] = hash[a][1];
            }
        }
    }

    int count = 0;
    unordered_set<int> diff;
    for (int i = 1; i < n + 1; i++)
    {
        if (!hash[i][0])
            count++;
        else
            diff.insert(hash[i][1]);
    }

    count += diff.size() - 1;

    cout << count;
}