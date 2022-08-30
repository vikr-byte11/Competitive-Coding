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
vi adjr[2000005];
ll vis[2000005];
ll k = 1;
ll ans[2000005];
stack<int> st;
void dfs(ll u)
{
    vis[u] = 1;
    for (auto x : adj[u])
        if (!vis[x])
            dfs(x);
    st.push(u);
}
void dfs2(ll u)
{
    vis[u] = 1;
    ans[u] = k;
    for (auto x : adjr[u])
        if (!vis[x])
            dfs2(x);
}
void rever(ll n)
{
    for (int i = 1; i <= n; i++)
        for (auto x : adj[i])
            adjr[x].push_back(i);
}
void solve()
{
    //strongly connected components
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    //now reverse the graph
    rever(n);
    memset(vis, 0, sizeof(vis));
    while (!st.empty())
    {
        ll tp = st.top();
        //cout << tp << endl;
        st.pop();
        if (!vis[tp])
        {
            dfs2(tp);
            k++;
        }
    }
    cout << k - 1 << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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