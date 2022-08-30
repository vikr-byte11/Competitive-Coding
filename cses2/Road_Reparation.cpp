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
ll parent[200005];
ll rnk[200005];
ll fi(ll x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = fi(parent[x]);
}
bool unio(ll x, ll y)
{
    ll a = fi(x);
    ll b = fi(y);
    if (a == b)
        return false;
    if (rnk[a] < rnk[b])
    {
        parent[a] = b;
    }
    else if (rnk[a] > rnk[b])
        parent[b] = a;
    else
    {
        rnk[a]++;
        parent[b] = a;
    }
    return true;
}
const int Mod = 1e9 + 7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    ll f = m;
    while (f--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        edges.push_back({z, x, y});
    }
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    srt(edges);
    ll ans = 0;
    int i = 0, j = 0;
    for (auto e : edges)
    {
        if (unio(e[1], e[2]))
            ans += e[0], i++;
    }
    if (i != n - 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << ans << endl;
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