#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    if (n == 1)
    {
        if (k == 0)
            cout << 1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    vector<ll> a(n, 0);
    ll left = (n - 2) / 2;
    a[0] = k - left;
    a[1] = 2 * (k - left);
    ll val = 1, i = 2;
    if (a[0] <= 0)
    {
        cout << -1 << endl;
        return 0;
    }
    while (i < n)
    {
        if (val == a[0] || val == a[1])
        {
            val++;
            continue;
        }
        a[i] = val;
        val++;
        i++;
    }
    for (auto it : a)
        cout << it << " ";
    cout << endl;
}