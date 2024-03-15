#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <iterator>
#include <vector>
using namespace std;
void fastscan(int &number)
{
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    if (negative)
        number *= -1;
}

int maxSum(vector<int> array, int n, int k)
{
    int maxWidth = 0;
    if (n == 0)
    {
        return 0;
    }

    int idxStart = 0, idxMax = 0, idxMin = 0;
    int min = array[0], max = array[0];
    for (int idx = 0; idx < n; idx++)
    {
        int val = array[idx];
        if (val > max)
        {
            if (val - min <= k)
            {
                max = val;
                idxMax = idx;
            }
            else
            {
                int mn = val;
                for (int j = idx - 1; j >= 0; j--)
                {
                    int v = array[j];
                    if (val - v > k)
                    {
                        idxStart = j + 1;
                        break;
                    }

                    if (v < mn)
                    {
                        mn = v;
                    }
                }
                min = mn;
            }
        }

        if (maxWidth < idx - idxStart)
        {
            maxWidth = idxMax - idxMin;
        }
    }
    return maxWidth + 1;
}

// Function Call
int main()
{
    int n, k;
    fastscan(n);
    fastscan(k);
    vector<int> integers(n);
    for (int j = 0; j < n; j++)
    {
        fastscan(integers[j]);
    }

    cout << maxSum(integers, n, k) << "\n";
}