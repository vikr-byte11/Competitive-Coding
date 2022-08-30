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
vector<ll> adj[200005];
ll dp[200005][2];
void dfs(ll src, ll par)
{
    //dp[src][0]->pairs if src is not included
    //dp[src][1]->pairs if src is included
    dp[src][0] = dp[src][1] = 0;
    bool leaf = 1;
    for (auto x : adj[src])
    {
        if (x != par)
        {
            leaf = 0;
            dfs(x, src);
        }
    }
    if (leaf)
        return;
    vi prefix, suffix;
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        prefix.push_back(max(dp[x][0], dp[x][1]));
        suffix.push_back(max(dp[x][0], dp[x][1]));
    }
    for (int i = 1; i < prefix.size(); i++)
        prefix[i] += prefix[i - 1];
    for (int i = suffix.size() - 2; i >= 0; i--)
        suffix[i] += suffix[i + 1];
    dp[src][0] = suffix[0];
    int eno = 0;
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        int lft = eno == 0 ? 0 : prefix[eno - 1];
        int ryt = eno == suffix.size() - 1 ? 0 : suffix[eno + 1];
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
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]);
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