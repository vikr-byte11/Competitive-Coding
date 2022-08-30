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
ll _timer = 0;
vector<ll> adj[200005];
ll innode[200005];
ll subsize[200005];
ll v[200005];
ll dp[200005];
ll stree[800005];
void dfs(ll src, ll par)
{
    innode[src] = ++_timer;
    subsize[src] = 1;
    dp[innode[src]] = v[src];
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        dfs(x, src);
        subsize[src] += subsize[x];
    }
}
void build(ll s, ll e, ll tnode)
{
    if (s == e)
    {
        stree[tnode] = dp[s];
        return;
    }
    ll mid = s + (e - s) / 2;
    build(s, mid, 2 * tnode);
    build(mid + 1, e, 2 * tnode + 1);
    stree[tnode] = stree[2 * tnode] + stree[2 * tnode + 1];
}
void upd(ll s, ll e, ll tnode, ll pos, ll diff)
{
    if (s > pos || e < pos)
        return;
    stree[tnode] += diff;
    if (s == e)
        return;
    ll mid = s + (e - s) / 2;
    upd(s, mid, 2 * tnode, pos, diff);
    upd(mid + 1, e, 2 * tnode + 1, pos, diff);
}
ll gsum(ll s, ll e, ll lreq, ll rreq, ll tnode)
{
    if (s > rreq || e < lreq)
        return 0;
    if (s >= lreq and e <= rreq)
        return stree[tnode];
    ll mid = s + (e - s) / 2;
    ll op1 = gsum(s, mid, lreq, rreq, 2 * tnode);
    ll op2 = gsum(mid + 1, e, lreq, rreq, 2 * tnode + 1);
    return op1 + op2;
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 2; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1); // serialize this tree
    build(1, n, 1);
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x, y;
            cin >> x >> y;
            upd(1, n, 1, innode[x], y - dp[innode[x]]);
            dp[innode[x]] = y;
        }
        else
        {
            ll z;
            cin >> z;
            cout << gsum(1, n, innode[z], innode[z] + subsize[z] - 1, 1) << endl;
        }
    }
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