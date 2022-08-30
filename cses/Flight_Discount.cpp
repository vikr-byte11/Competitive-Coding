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
#define mp make_pair
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
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
typedef map<ll, ll> mii;

const ll md = 1e9 + 7;
// &*!=
// ()@
//Vikram1234@

void dij(ll src, vi &dist, vector<vector<ll>> vp[])
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        ll a = x.first;
        ll b = x.second;
        if (dist[b] < a)
            continue;
        for (auto child : vp[b])
        {
            if (dist[child[0]] > dist[b] + child[1])
            {
                dist[child[0]] = dist[b] + child[1];
                pq.push({dist[child[0]], child[0]});
            }
        }
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> vp[n + 1];
    vector<vector<ll>> vp2[n + 1];
    vector<vector<ll>> edges;
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        vp[x].push_back({y, z});
        vp2[y].push_back({x, z});
        edges.push_back({x, y, z});
    }
    vi dist1(n + 1, 1e17);
    vi dist2(n + 1, 1e17);

    // we need dijkstra 2 times
    dij(1, dist1, vp);
    // iguess i have  to  reverse edges for this
    dij(n, dist2, vp2);
    ll ans = 1e17 + 10;
    for (auto e : edges)
    {
        ll d1 = dist1[e[0]];
        ll d2 = dist2[e[1]];
        ans = min(ans, d1 + d2 + (e[2] / 2));
    }
    cout << ans << endl;
}
int main()
{

    FAST_IO
    ll t = 1;
    //cin>>t;

    while (t--)
    {
        solve();
    }
    return 0;
}