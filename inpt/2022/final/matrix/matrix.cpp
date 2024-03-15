#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    int t = 0;
    for (int i = 0; i < n; i++)
        t += v[i][i];

    int r = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, bool> hr;
        for (int j = 0; j < n; j++)
        {
            if (hr[v[i][j]])
            {
                r++;
                break;
            }

            hr[v[i][j]] = true;
        }

        unordered_map<int, bool> hc;
        for (int j = 0; j < n; j++)
        {
            if (hc[v[j][i]])
            {
                c++;
                break;
            }

            hc[v[j][i]] = true;
        }
    }

    cout << t << " " << r << " " << c << endl;
}