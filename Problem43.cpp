#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n), prefix(n + 1);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long int val = 0;
    for (int i = 1; i <= n; i++)
    {
        int q = n / i;
        int rem = n % i;
        if (q & 1)
        {
            prefix[1] += 1;
            prefix[i] -= 1;
        }
        prefix[1] += 1;
        prefix[rem + 1] -= 1;
    }
    for (int i = 1; i <= n; i++)
        prefix[i] += prefix[i - 1];

    for (int i = 0; i < n; i++)
    {
        if(prefix[i+1]&1)val ^=(i+1);
        val ^= arr[i];
    }
    cout << val << endl;

    return 0;
}