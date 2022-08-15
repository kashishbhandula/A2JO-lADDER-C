#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
vector<vector<ll>> graph, graph1;
vector<ll> color, cost;
ll ans, ways;
void Dfs(ll root, stack<ll> &st)
{
    color[root] = 1;

    for (auto it : graph[root])
    {
        if (color[it] == 0)
        {
            Dfs(it, st);
        }
    }
    st.push(root);
}
ll Dfs(ll root, map<ll, ll> &mp)
{
    mp[cost[root]]++;
    color[root] = 1;
    //  cout << root << " ";
    ll mn = cost[root];
    for (auto it : graph[root])
    {
        if (color[it] == 0)
        {
            mn = min(mn, Dfs(it, mp));
        }
    }
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    cost.assign(n + 1, 0);
    color.assign(n + 1, 0);
    ans = 0, ways = 1;
    graph.assign(n + 1, vector<ll>());
    graph1.assign(n + 1, vector<ll>());
    vector<pair<ll, ll>> store;
    for (ll i = 1; i <= n; i++)
        cin >> cost[i];
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        store.push_back({cost[u], u});
        graph[u].push_back(v);
        graph1[v].push_back(u);
    }
    stack<ll> st;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            Dfs(i, st);
        }
    }
    graph = graph1;
    color.assign(n + 1, 0);
    while (!st.empty())
    {
        int root = st.top();
        st.pop();
        if (color[root] == 0)
        {
            map<ll, ll> mp;
            ll val = Dfs(root, mp);
            ways *= mp[val];
            ways%=mod;
            ans += val;
            
            //  cout <<mp[val]<< endl;
        }
    }
    cout << ans << " " << ways << endl;
}