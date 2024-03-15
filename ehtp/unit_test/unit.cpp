#include <bits/stdc++.h>
using namespace std;

#define pp pair<int, pair<int, int>>

int main()
{
    vector<int> v = {4, 9, 13};
    auto idx = lower_bound(v.begin(), v.end(), 10);
    cout << distance(v.begin(), idx) << endl;
    v.insert(idx, 10);

    for (auto &b : v)
        cout << b << " ";
}