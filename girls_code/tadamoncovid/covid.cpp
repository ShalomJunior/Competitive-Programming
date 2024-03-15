#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> v;
vector<int> ans;
set<int> s;

int main()
{
    cin >> n;
    v.resize(n);
    ans.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ans[n - 1] = 0;
    s.insert(v[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > v[i + 1])
        {
            ans[i] = ans[i + 1] + 1;
            s.insert(v[i]);
            // int idx = distance(s.begin(), res.first);
            //  cout << "insert : " << v[i] << "position :" << idx << endl;
            continue;
        }
        else
        {

            auto res = s.insert(v[i]);
            int idx = distance(s.begin(), res.first);
            // cout << "insert : " << v[i] << "position :" << idx << endl;
            ans[i] = idx;
        }
    }

    int sm = 0;
    for (auto v : ans)
        sm += v;
    cout << sm;
}