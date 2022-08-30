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
vi adj[200005];
ll dp[200005][20];
ll ft[400010];
ll val[200005];
ll start[200005];
ll ed[200005];
ll timer = 1;
ll lvl[200005];
ll lft(ll u, ll k)
{
    if (u == -1 || k == 0)
        return u;
    ll ans = -1;
    for (int i = 19; i >= 0; i--)
    {
        if (k >= (1 << i))
        {
            ans = lft(dp[u][i], k -= (1 << i));
            break;
        }
    }
    return ans;
}
ll lca(ll a, ll b)
{
    if (lvl[a] < lvl[b])
        swap(a, b);
    a = lft(a, lvl[a] - lvl[b]);
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
    {
        if (dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}
void dfs(ll src, ll par, ll lv)
{
    start[src] = timer;
    ft[timer] = src;
    timer++;
    lvl[src] = lv;
    dp[src][0] = par;
    for (int i = 1; i <= 19; i++)
    {
        if (dp[src][i - 1] != -1)
            dp[src][i] = dp[dp[src][i - 1]][i - 1];
        else
            dp[src][i] = -1;
    }
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        dfs(x, src, lv + 1);
    }
    ed[src] = timer;
    ft[timer] = src;
    timer++;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 2; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1, 0);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (start[a] > start[b])
            swap(a, b);
        if (lca(a, b) == a)
        {
            //start time of a and start time of b
            ll sa = start[a];
            ll sb = start[b];
            bool f = false;
            for (int i = sa; i <= sb; i++)
                if (ft[i] == c)
                    f = !f;
            if (f)
                cout << "Find\n";
            else
                cout << "NotFind\n";
        }
        else
        {
            ll eta = ed[a];
            ll stb = start[b];
            ll lc = lca(a, b);
            bool f = false;
            for (int i = eta; i <= stb; i++)
            {
                if (ft[i] == c)
                {
                    f = !f;
                }
            }
            if (f == true || ft[start[lc]] == c)
                cout << "Find\n";
            else
                cout << "NotFind\n";
        }
    }
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