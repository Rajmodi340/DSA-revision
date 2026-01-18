#include<iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;
int findShortestCycle(int n, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    for (vector<int> vec : edges)
    {
        int u = vec[0];
        int v = vec[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        vector<int> parent(n, -1);
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
                else if (parent[u] != v)
                {
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    cout<<findShortestCycle(n,edges)<<endl;
    return 0;
}