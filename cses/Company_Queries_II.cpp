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
// binary lifting
ll dp[200005][20];
// dp[x][i]->node at 2^i levels up from x
ll lv[200005];
void dfs(ll src, ll par, ll lvl)
{
    dp[src][0] = par;
    for (int i = 1; i <= 19; i++)
    {
        if (dp[src][i - 1] != -1)
            dp[src][i] = dp[dp[src][i - 1]][i - 1];
        else
            dp[src][i] = -1;
    }
    lv[src] = lvl;
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        dfs(x, src, lvl + 1);
    }
}
ll qry(ll u, ll lev)
{
    if (u == -1 || lev == 0)
        return u;
    ll ans = -1;
    for (int i = 19; i >= 0; i--)
    {
        if (lev >= (1 << i))
        {
            ans = qry(dp[u][i], lev - (1 << i));
            break;
        }
    }
    return ans;
}
ll fun(ll a, ll b)
{
    if (lv[a] < lv[b])
        swap(a, b);
    a = qry(a, lv[a] - lv[b]);
    //     ll lo = 0, hi = lv[a];
    //     ll ans = -1;
    //     while (lo <= hi)
    //     {
    //         ll mid = lo + (hi - lo) / 2;
    //         ll fa = qry(a, mid);
    //         ll fb = qry(b, mid);
    //         if (fa == fb)
    //         {
    //             ans = mid;
    //             hi = mid - 1;
    //         }
    //         else
    //             lo = mid + 1;
    //     }
    //     return qry(a, ans);
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
    return qry(a, 1);
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1, -1, 0);
    while (q--)
    {
        // we need a video;
        ll a, b;
        cin >> a >> b;
        cout << fun(a, b) << endl;
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