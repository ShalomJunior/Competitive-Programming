#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> v;
vector<int> nb;

int np(int x)
{
    int ex = log(x) / log(2);
    if (pow(2, ex) == x)
        return x;
    return pow(2, ex + 1);
}

void update(int idx, int val)
{
    idx += n;
    bool uk = v[idx] == -1;
    int diff = uk ? val + 1 : val - v[idx];

    while (idx > 0)
    {
        v[idx] += diff;
        uk ? nb[idx]++ : nb[idx];
        idx /= 2;
    }
}

pair<long long, int> sm(int idx1, int idx2)
{
    idx1 += n;
    idx2 += n;
    pair<long long, int> frac = make_pair(0, 0);
    while (idx1 <= idx2)
    {
        if (idx1 % 2 == 1)
            frac.first += v[idx1], frac.second += nb[idx1++];
        if (idx2 % 2 == 0)
            frac.first += v[idx2], frac.second += nb[idx2--];

        idx1 /= 2, idx2 /= 2;
    }
    return frac;
}

int main()
{
    int temp;
    cin >> temp;
    n = np(temp);

    v.resize(2 * n);
    nb.resize(2 * n);

    for (int i = 0; i < temp; i++)
    {
        long long c;
        cin >> c;
        nb[i + n] = (c == -1) ? 0 : 1;
        v[i + n] = c;
    }

    for (int i = n - 1; i > 0; i--)
    {
        nb[i] = nb[2 * i] + nb[2 * i + 1];
        v[i] = v[2 * i] + v[2 * i + 1];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int T, a, b;
        cin >> T >> a >> b;
        if (T == 1)
        {
            update(a, b);
        }
        else if (T == 2)
        {
            pair<long long, int> frac = sm(a, b);
            if (frac.second == 0)
            {
                cout << -1 << endl;
                continue;
            }

            double s = static_cast<double>(frac.first + (b - a + 1 - frac.second)) / frac.second;
            printf("%.9f\n", s);
        }
    }
}