#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }

    return (x > 1 && true);
}

int cum(int res, unordered_map<int, int> &mp)
{
    auto mini = min_element(mp.begin(), mp.end(), [](const auto &a, const auto &b)
                            { return a.second < b.second; });

    if (mini->second != 0)
    {
        long long sm = 0;
        for (auto it : mp)
        {
            if (it.second == mini->second)
            {
                sm *= it.first;
                mp.erase(it);
            }
            else
            {
            }
        }
        res +=
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    cout << "Solving " << n << endl;
    int cp = n;
    unordered_map<int, int> mp;
    for (int i = 2; i < n;)
    {
        if (is_prime(cp))
        {
            mp[cp]++;
            break;
        }
        if (is_prime(i) && (cp % i == 0))
            mp[i]++, cp /= i;
        else
            i++;
    }

    cout << "Map" << endl;
    for (auto p : mp)
        cout << p.first << " " << p.second << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        solve();
}