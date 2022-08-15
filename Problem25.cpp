#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(ll total, ll mid, vector<ll> &price, vector<ll> &cnt, vector<ll> &required)
{
    for (ll i = 0; i < 3; i++)
    {
        ll val = max(0ll, mid * required[i] - cnt[i]);
    
        if (price[i] * val > total)
            return false;
        else
            total -= (price[i] * val);
    }
    return true;
}
int main()
{
    string str;
    cin >> str;
    vector<ll> cnt(3), price(3), required(3);
    required[0] = count(str.begin(), str.end(), 'B');
    required[1] = count(str.begin(), str.end(), 'S');
    required[2] = count(str.begin(), str.end(), 'C');

    for (ll i = 0; i < 3; i++)
        cin >> cnt[i];
    for (ll i = 0; i < 3; i++)
        cin >> price[i];
    ll total, ans = 0;
    cin >> total;
    ll low = 0, high = 1e13;
    while (low <= high)
    {
        ll mid = (low + high) >> 1;
        if (check(total, mid, price, cnt, required))
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}