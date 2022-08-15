#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll top = 1e7;
bool isPrime[10000001];
ll st[10000001];
ll mp[10000001];

void Build()
{
    for (ll i = 2; i <= top; i++)
    {
        if (!isPrime[i])
        {
            st[i] = mp[i];
            for (ll j = 2 * i; j <= top; j += i)
            {
                isPrime[j] = true;

                st[i] += mp[j];
            }
        }
    }
    for (ll i = 1; i <= top; i++)
    {
        st[i] += st[i - 1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    Build();
    ll m;

    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        if (u >= top)
        {
            cout << 0 << endl;
        }
        else
            cout << st[min(v, top)] - st[u - 1] << endl;
    }
}