#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, a, b, c;
    cin >> N >> a >> b >> c;

    if (a < b)
        swap(a, b);
    if (a < c)
        swap(a, c);
    if (b < c)
        swap(b, c);

    if (a == b)
    {
        if (c > 2 * (N - a))
            cout << "impossible";
        else
            cout << "possible";
    }
    else
    {
        if (c > (N - b + N - a))
            cout << "impossible";
        else
            cout << "possible";
    }
}