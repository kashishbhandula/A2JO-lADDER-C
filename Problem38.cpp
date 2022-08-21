#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> arr, goal;
vector<int> vis;
vector<int> value;
vector<int> ans;

void Dfs(int node, int flag = 0)
{
    vis[node] = true;
    // cout << node <<endl;
    if (value[flag] & 1)
    {
        arr[node] = 1 - arr[node];
    }
    if (goal[node] != arr[node])
    {
        value[flag]++;
        ans.push_back(node);
    }
    for (auto it : graph[node])
    {
        if (!vis[it])
        {

            Dfs(it, 1 - flag);
        }
    }
    if (goal[node] != arr[node])
    {
        value[flag]--;
    }
}
int main()
{
    int n;
    cin >> n;
    graph.assign(n + 1, vector<int>());
    arr.assign(n + 1, 0);
    goal.assign(n + 1, 0);
    value.assign(2, 0);
    vis.assign(n + 1, false);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        cin >> goal[i];
    Dfs(1);
    cout << ans.size() << endl;
    for (auto it : ans) cout << it << endl;
    // cout << endl;

    return 0;
}