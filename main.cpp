#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 1e9; // infinity value for initial distances

vector<vector<pair<int, int>>> adj; // adjacency list
vector<int> dist;                   // distances from source vertex
vector<int> parent;                 // parents of each vertex in the shortest path tree

void dijkstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // set distances to all vertices to infinity except source vertex
    dist.assign(adj.size(), INF);
    dist[source] = 0;

    // push source vertex into the priority queue
    pq.push({dist[source], source});

    // iterate through priority queue to visit all vertices
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // iterate through all adjacent vertices of u
        for (auto [v, weight] : adj[u])
        {
            // check if new path through u is shorter
            if (dist[u] + weight < dist[v])
            {
                // update distance and parent of v
                dist[v] = dist[u] + weight;
                parent[v] = u;

                // push v into the priority queue
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m; // number of vertices and edges
    cin >> n >> m;

    // initialize adjacency list and parent vector
    adj.resize(n);
    parent.resize(n, -1);

    // read in edges and weights
    for (int i = 0; i < m; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    int source, dest; // source and destination vertices
    cin >> source >> dest;

    dijkstra(source);

    // output shortest distance and path
    cout << "Shortest distance from " << source << " to " << dest << " is: " << dist[dest] << endl;
    cout << "Shortest path: ";
    int u = dest;
    while (u != -1)
    {
        cout << u << " ";
        u = parent[u];
    }
    cout << endl;

    return 0;
}
