/**
    You just can't beat the one who never gives up

                            /T /I
                              / |/ | .-~/
                          T\ Y  I  |/  /  _
         /T               | \I  |  I  Y.-~/
        I l   /I       T\ |  |  l  |  T  /
     T\ |  \ Y l  /T   | \I  l   \ `  l Y
 __  | \l   \l  \I l __l  l   \   `  _. |
 \ -l  `\   `\  \  \ ~\  \   `. .-   |
  \   ~-. "-.  `  \  ^._ ^. "-.  /  \   |
.--~-._  ~-  `  _  ~-.-"-." . /._ ." ./
 >--.  ~-.   ._  ~>-"    "\   7   7   ]
^._"--._    ~-{  .- .  `\ Y . /    |
 <_ ~"-.  ~       //   \   \I  Y   : |
   ^-._           ~(/   \   >.:   | l___
       ^--.,_.-"  /_/   !  `-."--l_ /     ~"-.
              (_/ .  (   /'     ""--,Y   -=b-. _)
               (_/ .  \  :           / l      c"~o \
                \ /    `.    .     .^   \_.-"--.  )
                 (_/ .   `  /     /       !       )/
                  / / _.   '.   .':      /        '
                  ~(/ .   /    _  `  .-<
                    /_/ . ' .-~" `.  / \  \          ,z=.
                    ( /   '  :   | K   "-.-.__//
                      "-,.    l   I/ \_    _{--->.(==.
                       //(     \  <    ""     //
                      /' /\     \  \     ,v=.  ((
                    .^. / /\     "  }__ //===-  `
                   / / ' '  "-.,__ {---(==-
                 .^ '       :  T  ~"   ll       -Sparrow
                / .  .  . : | :!        \
               (_/  /   | | j-"          ~^

**/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define fo(i, a) for (int i = 0; i < a; i++)
#define fod(i, a, b) for (int i = a; i >= b; i--)
#define ff first
#define ss second
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ip(v)         \
    for (auto &x : v) \
    cin >> x
#define op(v)             \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl
#define tr(v) for (auto x : v)
#define srt(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define clr(x) memset(x, 0, sizeof(x))

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef map<int, int> mii;

const int Mod = 1e9 + 7;

void dijkstra(ll src, vi &dist, vpii adj[])
{
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        if (dist[x.second] < x.first)
            continue;
        for (auto child : adj[x.second])
        {
            if (dist[child.first] > dist[x.second] + child.second)
            {
                dist[child.first] = dist[x.second] + child.second;
                pq.push({dist[child.first], child.first});
            }
        }
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vpii adj[n + 1];
    vpii adj2[n + 1];
    vector<vector<ll>> ed;
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj2[y].push_back({x, z});
        ed.push_back({x, y, z});
    }
    vi dist1(n + 1, 1e17);
    vi dist2(n + 1, 1e17);
    // in directed graph dist from a->b not equal to b->a
    // so reverse and get shortest dist to reach n from any n
    dijkstra(1, dist1, adj);
    dijkstra(n, dist2, adj2);

    ll ans = INT_MAX;
    for (auto x : ed)
    {
        ll a = x[0];
        ll b = x[1];
        ll c = x[2];
        ans = min(ans, dist1[x[0]] + dist2[x[1]] + (x[2] / 2));
    }
    cout << ans << endl;
}
int main()
{
    FAST_IO
    ll t = 1;
    // cin>>t;

    while (t--)
    {
        solve();
    }
    return 0;
}