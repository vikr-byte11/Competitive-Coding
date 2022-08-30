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
vi adj[200005], adjc[200005], adjr[200005];
vi vis(200005, 0), comp(200005);
stack<ll> st;
ll dp[200005];
ll k = 1;
vi smc(200005, 0);
void dfs(ll src)
{
    vis[src] = 1;
    for (auto x : adj[src])
        if (!vis[x])
            dfs(x);
    st.push(src);
}
void dfs2(ll src)
{
    comp[src] = k;
    vis[src] = 1;
    for (auto x : adjr[src])
        if (!vis[x])
            dfs2(x);
}
ll fun(ll src)
{
    if (dp[src] != -1)
        return dp[src];
    // then calculate
    dp[src] = smc[src];
    // search in comp graph of there
    for (auto x : adjc[src])
        dp[src] = max(dp[src], fun(x) + smc[src]);
    return dp[src];
}
const int Mod = 1e9 + 7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vi grp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> grp[i];
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    // reverse graph
    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
            adjr[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    while (!st.empty())
    {
        auto x = st.top();
        st.pop();
        if (!vis[x])
        {
            dfs2(x);
            k++;
        }
    }

    for (int i = 1; i <= n; i++)
        smc[comp[i]] += grp[i];
    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            if (comp[i] == comp[x])
                continue;
            adjc[comp[i]].push_back(comp[x]);
        }
    }
    // done with the graph
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
        ans = max(ans, fun(comp[i]));
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