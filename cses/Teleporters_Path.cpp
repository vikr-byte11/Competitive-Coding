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
vi adj[2000005];
vi in(2000005, 0);
vi out(2000005, 0);
vi vis(2000005, 0);
ll n, m, sn, en;
vi p;
void dfs(ll src)
{
    vis[src] = 1;
    for (auto x : adj[src])
        if (!vis[src])
            dfs(x);
    p.push_back(src);
}
bool check()
{
    ll c = 0, s1, s2;
    sn = 0, en = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] - out[i] > 1 or out[i] - in[i] > 1)
            return false;
        else if (in[i] - out[i] == 1)
            en++, s2 = i;
        else if (out[i] - in[i] == 1)
            sn++, s1 = i;
        else if (in[i] == out[i])
            c++;
    }
    if (s1 != 1 || s2 != n)
        return false;
    if (!(c == n - 2 && sn == 1 && en == 1))
        return false;
    return (en == 0 and sn == 0) or (en == 1 and sn == 1);
}
void fsnode()
{
    for (int i = 1; i <= n; i++)
    {
        if (out[i] - in[i] == 1)
        {
            sn = i;
            return;
        }
        if (out[i] > 0)
            sn = i;
    }
}
vi path;
void feuler(ll node)
{
    while (out[node])
    {
        out[node]--;
        ll tmp = adj[node][adj[node].size() - 1];
        adj[node].pop_back();
        feuler(tmp);
    }
    path.push_back(node);
}
void solve()
{
    //eulerian path in directed edges
    //simple
    cin >> n >> m;
    ll g = m;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        out[x]++;
        in[y]++;
    }
    //check if there is euler path
    if (!check())
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    feuler(1);
    if (path.size() != g + 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    rev(path);
    op(path);
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