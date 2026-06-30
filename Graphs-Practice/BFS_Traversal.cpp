#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>


using namespace std;

// Implement BFS here
vector<int> bfsOfGraph(int V, vector<vector<int>>& adj)
{
   vector<int> res;
   unordered_set<int> visited;
   queue<int> q;
   q.push(0);

   while(!q.empty()){
    int current = q.front();
    res.push_back(current);
    q.pop();
    for(int node : adj[current]){
    if(!visited.count(node)){
        visited.insert(node);
        q.push(node);
    }
    }
   }
   return res;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    // Undirected Graph
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for (int node : ans)
        cout << node << " ";

    return 0;
}