// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

// Number of vertices in given graph
#define V 502
int g;
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < g; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
long long fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < g; u++)
        for (v = 0; v < g; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    long long max_flow = 0;
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    int N;
    cin >> g >> N;
    int graph[V][V];
    memset(graph, 0, sizeof(graph));
    int tmp = N;
    while (N--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        graph[x][y] = z;
    }
    cout << fordFulkerson(graph, 0, g - 1);

    return 0;
}
