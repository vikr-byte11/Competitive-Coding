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
ll in[200005];
ll out[200005];
void dfs1(ll src, ll par)
{
    in[src] = 0;
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        dfs1(x, src);
        in[src] = max(in[src], 1 + in[x]);
    }
}
void dfs2(ll src, ll par)
{
    //here in[src] and out[src] is done
    //we have to get out[child of x]
    ll mx1 = -1, mx2 = -1;
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        if (in[x] > mx1)
        {
            mx2 = mx1;
            mx1 = in[x];
        }
        else if (in[x] > mx2)
            mx2 = in[x];
    }
    //now get out[x] for every child

    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        ll use = mx1;
        if (mx1 == in[x])
            use = mx2;
        ll op1 = 2 + use;
        ll op2 = 1 + out[src];
        out[x] = max(op1, op2);
        dfs2(x, src);
    }
}
void solve()
{
    ll n;
    cin >> n;
    fo(i, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //this is in-out dp
    dfs1(1, -1); //in call
    dfs2(1, -1);
    // for (int i = 1; i <= n; i++)
    //     cout << in[i] << " ";
    for (int i = 1; i <= n; i++)
        cout << max(in[i], out[i]) << " ";
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