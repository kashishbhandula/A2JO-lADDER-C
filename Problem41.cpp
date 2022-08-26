#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(arr.begin(), arr.end(), arr[i] + d) - arr.begin();
        pos--;
        long long int tt = pos - i;

        ans += (tt * (tt - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}