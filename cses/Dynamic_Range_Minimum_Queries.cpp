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
void fbuild(int ns, int ne, int tnode, vi &v, vi &stree)
{
    if (ns == ne)
    {
        stree[tnode] = v[ns];
        return;
    }
    ll mid = ns + (ne - ns) / 2;
    fbuild(ns, mid, 2 * tnode, v, stree);
    fbuild(mid + 1, ne, 2 * tnode + 1, v, stree);
    stree[tnode] = min(stree[2 * tnode], stree[2 * tnode + 1]);
}
ll getsum(vi &v, vi &stree, int ns, int ne, int tnode, int lreq, int rreq)
{
    // no overlap
    if (ne < lreq || ns > rreq)
        return INT_MAX;
    //full overlap
    if (ns >= lreq and ne <= rreq)
        return stree[tnode];
    ll mid = ns + (ne - ns) / 2;
    return min(getsum(v, stree, ns, mid, 2 * tnode, lreq, rreq), getsum(v, stree, mid + 1, ne, 2 * tnode + 1, lreq, rreq));
}
void upd(vi &v, vi &stree, int ns, int ne, int tnode, int pos, int diff)
{
    if (pos < ns || pos > ne)
        return;
    if (ns == ne)
    {
        stree[tnode] = v[ns];
        return;
    }
    int mid = (ns + ne) / 2;
    upd(v, stree, mid + 1, ne, 2 * tnode + 1, pos, diff);
    upd(v, stree, ns, mid, 2 * tnode, pos, diff);
    stree[tnode] = min(stree[2 * tnode], stree[2 * tnode + 1]);
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    vi v(n + 2), stree(4 * n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    fbuild(1, n, 1, v, stree);
    while (q--)
    {
        ll type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
        {
            ll diff = y;
            v[x] = y;
            upd(v, stree, 1, n, 1, x, diff);
        }
        else
            cout << getsum(v, stree, 1, n, 1, x, y) << endl;
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