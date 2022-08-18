#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
vector<vector<ll>> cnt;
ll x, y, m, n;
ll dp[2][1001][1001];

ll Recursion(ll idx, ll curr, ll tt)
{
    if (idx == m)
    {
        if (tt > x || tt == 1)
            return 0;
        else
            return 1e17;
    }

    if (dp[curr][idx][tt] != -1)
        return dp[curr][idx][tt];
    ll cst = 1e17, val = 0;

    if (tt == y)
    {
        cst = min(cst, cnt[idx][1 - curr] + Recursion(idx + 1, 1 - curr, 1));
    }
    else
    {
        cst = min(cst, cnt[idx][1 - curr] + Recursion(idx + 1, curr, tt + 1));
        if (tt >= x)
            cst = min(cst, cnt[idx][1 - curr] + Recursion(idx + 1, 1 - curr, 1));
    }
    return dp[curr][idx][tt] = cst;
}
int main()
{

    cin >> n >> m >> x >> y;
    vector<string> str(n);
    cnt.assign(m, vector<ll>(2, 0));
    for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < 1001; j++)
        {
            for (ll k = 0; k < 1001; k++)
                dp[i][j][k] = -1;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (str[j][i] == '#')
                cnt[i][0]++;
            else
                cnt[i][1]++;
        }
    }
    cout << min(Recursion(0ll, 0, 1), Recursion(0ll, 1, 1)) << endl;

    return 0;
}