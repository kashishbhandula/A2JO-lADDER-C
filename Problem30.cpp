#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//
int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<ll> left(n + 1), right(n + 1,n);
    for(ll i=1;i<=n;i++)cin>>a[i];
    for (ll i = 2; i <=n; i++)
    {
        if (a[i] >a[i - 1])
            left[i] = i;
        else
            left[i] = left[i - 1];
    }
    for (ll i = n - 1; i >= 1; i--)
    {
        if (a[i] > a[i + 1])
            right[i] = i;
        else
            right[i] = right[i + 1];
    }
    // for(auto it:left)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    //  for(auto it:right)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        // cout<<right[l]<<" "<<left[r]<<" ";
        if(right[l]<left[r])
        {
            cout<<"No"<<endl;
        }
        else cout<<"Yes"<<endl;
        
    }
}