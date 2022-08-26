#include <bits/stdc++.h>
using namespace std;
// 18 17
int main()
{
    long long int n;
    cin >> n;
    if (n & 1)
    {
        long long int ans = n * max(1ll, n - 1) * max(1ll, n - 2);
        cout << ans << endl;
    }
    else
    {
        long long ans1 = n * max(1ll, n - 1) * max(2ll, n - 2);
        ans1 /= 2;
        long long ans2 = max(1ll, n) * max(1ll, n - 1) * max(1ll, n - 3);
        long long ans3 = max(1ll, n) * max(1ll, n - 1) * max(1ll, n - 5);
        long long ans4 = max(1ll, n - 1) * max(1ll, n - 2) * max(1ll, n - 3);

        if (n % 3 == 0 && n % 5 != 0)
        {
            cout << max({ans1, ans3, ans4}) << endl;
        }
        else if (n % 3 != 0)
        {
            cout << max({ans1, ans4, ans2}) << endl;
        }
        else
        {
            cout << max({ans1, ans4}) << endl;
        }
    }
}