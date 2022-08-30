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
vector<ll> adj[200005];
ll dp[200005][2];
ll vis[200005];
void dfs(int src, int par)
{
    dp[src][0] = dp[src][1] = 0;
    bool leaf = 1;
    vector<ll> pre, suff, cur;
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        dfs(x, src);
        leaf = 0;
    }
    if (leaf)
        return;
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        pre.push_back(max(dp[x][0], dp[x][1]));
        suff.push_back(max(dp[x][0], dp[x][1]));
    }
    for (int i = 1; i < pre.size(); i++)
        pre[i] += pre[i - 1];

    for (int i = suff.size() - 2; i >= 0; i--)
        suff[i] += suff[i + 1];
    dp[src][0] = suff[0];
    int eno = 0;
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        ll lft = eno == 0 ? 0 : pre[eno - 1];
        ll ryt = eno == suff.size() - 1 ? 0 : suff[eno + 1];
        dp[src][1] = max(dp[src][1], lft + ryt + dp[x][0] + 1);
        eno++;
    }
}
void solve()
{
    ll n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(dp, 0, sizeof(dp));
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]);
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