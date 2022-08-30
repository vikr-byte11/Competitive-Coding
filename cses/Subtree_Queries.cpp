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
ll dp[200005];
ll v[200005];
ll innode[200005];
ll subnode[200005];
ll stree[800005];
ll _timer = 0;
void dfs(ll src, ll par)
{
    subnode[src] = 1;
    innode[src] = ++_timer;
    dp[innode[src]] = v[src];
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        dfs(x, src);
        subnode[src] += subnode[x];
    }
}
void build(int ns, int ne, int tnode)
{
    if (ns == ne)
    {
        stree[tnode] = dp[ns];
        return;
    }
    ll mid = (ns + ne) / 2;
    build(ns, mid, 2 * tnode);
    build(mid + 1, ne, 2 * tnode + 1);
    stree[tnode] = stree[2 * tnode] + stree[2 * tnode + 1];
}
ll gsum(int ns, int ne, int tnode, int lreq, int rreq)
{
    // no overlap
    if (lreq > ne || rreq < ns)
        return 0;
    if (ns >= lreq and ne <= rreq)
        return stree[tnode];
    ll mid = (ns + ne) / 2;
    return gsum(ns, mid, 2 * tnode, lreq, rreq) + gsum(mid + 1, ne, 2 * tnode + 1, lreq, rreq);
}
void upd(int tnode, int ns, int ne, int pos, int diff)
{
    if (ns > pos || pos > ne)
        return;
    stree[tnode] += diff;
    if (ns != ne)
    {
        ll mid = (ns + ne) / 2;
        upd(2 * tnode, ns, mid, pos, diff);
        upd(2 * tnode + 1, mid + 1, ne, pos, diff);
    }
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
    dfs(1, -1);
    build(1, n, 1);
    while (q--)
    {
        ll type, x, y;
        cin >> type;
        if (type == 1)
        {
            cin >> x >> y;
            ll diff = y - dp[innode[x]];
            upd(1, 1, n, innode[x], diff);
            dp[innode[x]] = y;
        }
        else
        {
            cin >> x;
            cout << gsum(1, n, 1, innode[x], innode[x] + subnode[x] - 1) << endl;
        }
    }
    // this is prefix suffix type only
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