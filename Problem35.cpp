#include <bits/stdc++.h>
using namespace std;
bool check(long long int mid, vector<long long int> &arr)
{
    long long count = 0;
    long long int mx = 1e18;
    for (auto it : arr)
    {
        if (it > mid)
            return false;
        else
            count = min(count + (mid - it), mx);
    }
    if (count < mid)
        return false;
    else
        return true;
}
int main()
{
    long long int len;
    cin >> len;

    vector<long long int> arr(len);
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    long long int low = 0, high = 1e18, ans = 1e18;
    while (low <= high)
    {
        long long int mid = (low + high) >> 1;

        if (check(mid, arr))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << endl;
}