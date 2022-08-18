#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    ll sum1 = 0, sum2 = 0;
    for (ll i = 0; i < n; i++)
    {
        ll u;
        cin >> u;
        a[i] = {u, i + 1};
    }

    sort(a.begin(), a.end(), greater<pair<ll,ll>>());

    cout << ceil(n / 2.0) << endl;
    for (ll i = 0; i < n; i += 2)
    {
        cout << a[i].second << " ";
    }
    cout << endl;
    cout << n / 2 << endl;
    for (ll i = 1; i < n; i += 2)
    {
        cout << a[i].second << " ";
    }
    cout << endl;

    return 0;
}