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
ll in[200005];
ll subsize[200005];
ll out[200005];
vi adj[200005];
ll n;
void dfs(int src, int par)
{
    in[src] = 0;
    subsize[src] = 1;
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        dfs(x, src);
        in[src] += (subsize[x] + in[x]);
        subsize[src] += subsize[x];
    }
}
void dfs2(int src, int par)
{
    ll cans = in[src] + out[src];
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        ll s1 = in[x] + subsize[x]; // substract the current subtree
        ll s2 = n - subsize[x];     // add the outside subtree i.e in[x]+subsize[x]=n-subsize[in]
        out[x] = cans - s1 + s2;
        dfs2(x, src);
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1);
    dfs2(1, -1);
    for (int i = 1; i <= n; i++)
        cout << in[i] + out[i] << " ";
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