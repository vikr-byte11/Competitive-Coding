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
// Vikram1234@
vi deg(2000005, 0);
vi out(2000005, 0);
set<ll> adj[2000005];
vi vis(2000005, 0);
vi path;
void feuler(ll u)
{
    cout << u << endl;
    while (deg[u])
    {
        ll v = *adj[u].begin();
        adj[u].erase(v);
        adj[v].erase(u);
        deg[u]--, deg[v]--;
        feuler(v);
    }
    cout << "pushing " << u << endl;
    path.push_back(u);
}
void dfs(ll src)
{
    vis[src] = 1;
    for (auto x : adj[src])
        if (!vis[x])
            dfs(x);
}
void solve()
{
    // path in which sp and ep is same
    // and visits every edge once
    // i.e. eulerian path
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] % 2)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] and deg[i] != 0)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    feuler(1);
    op(path);
    rev(path);
    op(path);
    // we have to recursively call dfs
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