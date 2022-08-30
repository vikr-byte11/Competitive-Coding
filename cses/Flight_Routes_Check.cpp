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
vi adj[2000005][2];
vi adjr[2000005];
ll vis[2000005];
void dfs(ll src, ll x)
{
    vis[src] = 1;
    for (auto to : adj[src][x])
    {
        if (!vis[to])
            dfs(to, x);
    }
}
//more than one scc then also no
void solve()
{
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        adj[x][0].push_back(y);
        adj[y][1].push_back(x);
    }

    // if one vertex can both reached and be reached
    // by every other vertex then it evry other vertx
    // can be reached from any other vertex;
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO\n";
            cout << 1 << " " << i << endl;
            return;
        }
    }
    memset(vis, 0, sizeof(vis));
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO\n";
            cout << i << " " << 1 << endl;
            return;
        }
    }
    cout << "YES\n";
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