#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first < b.first)
        return true;
    if (a.first == b.first)
    {
        if (a.second >= b.second)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        a.push_back({u, v});
    }
    sort(a.begin(), a.end(), cmp);
    pair<ll, ll> curr = a[0], prev = curr;
    // for(auto it:a)cout<<it.first<<" "<<it.second<<endl;
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (curr.first < a[i].first && a[i].second < curr.second)
            ans++;

        else if (prev.first < a[i].first && a[i].second < prev.second)
            ans++;
        else if (a[i].second > curr.second)
        {
            if (curr.first != a[i].first)
                prev = curr;
            curr = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}