#include <bits/stdc++.h>
#define int long long
using namespace std;

//GEEKS
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
    int right);

// This function sorts the
// input array and returns the
// number of inversions in the array
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts and
        // call _mergeSortAndCountInv()
        // for each of the parts
        mid = (right + left) / 2;

        // Inversion count will be sum of
        // inversions in left-part, right-part
        // and number of inversions in merging
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        // Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// This function merges two sorted arrays
// and returns inversion count in the arrays.
int merge(int arr[], int temp[], int left, int mid,
    int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }

    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Driver code
void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    vector<int> ax(n), bx(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ax[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        bx[i] = b[i];
    }
    sort(ax.begin(), ax.end());
    sort(bx.begin(), bx.end());
    if (ax != bx) {
        cout << "NO" << endl;
        return;
    }
    int cnt_x = mergeSort(a, n);
    int cnt_y = mergeSort(b, n);
    cout << (cnt_x % 2 == cnt_y % 2 ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
