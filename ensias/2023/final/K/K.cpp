#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sm = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sm += a;
    }

    int b;
    cin >> b;
    if (sm < b)
        cout << "the secret ingrediant is crime";
    else if (sm == b)
        cout << "perfect balanced";
    else
        cout << "my time has come";
}