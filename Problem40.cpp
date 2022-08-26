#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a, b;
    cin >> a >> b;
    long long ans = 0;
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            ans += a / b;
            a %= b;
        }
        else
        {
            ans += b / a;
            b %= a;
        }
    }
    cout << ans << endl;

    return 0;
}