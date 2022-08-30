#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (long long i = a; i < b; i++)
#define ll long long
#define pb push_back
#define vll vector<long long>
#define vc vector
#define IOS ios_base::sync_with_stdio(0)
#define tie cin.tie(NULL), cout.tie(NULL)

void dfs(long long vertex, bool visited[], vector<long long> *AdjList)
{

    visited[vertex] = 1;

    for (auto i : AdjList[vertex])
        if (!visited[i])
            dfs(i, visited, AdjList);
}
int main()
{
    IOS;
    tie;
    int T;
    cin >> T;
    while (T--)
    {
        ll n, m;
        cin >> n >> m;
        vll adj[n];
        for (int i = 0; i < m; i++)
        {
            long long x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool a[n];
        memset(a, false, sizeof(a));
        dfs(0, a, adj);

        ll count = 0;
        while (!a[n - 1])
        {
            bool b[n];
            memset(b, false, sizeof(b));
            f(i, 0, n) if (a[i])
            {
                //    cout << i << endl;
                if (i + 1 < n)
                    dfs(i + 1, b, adj);
                if (i - 1 >= 0)
                    dfs(i - 1, b, adj);
            }
            f(i, 0, n)
                a[i] |= b[i];
            count++;
        }
        cout << count << endl;
    }
    return 0;
}