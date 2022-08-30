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
#define inf 1e17
#define ninf -1e17
const int Mod = 1e9 + 7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v;
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, -1 * z});
    }
    vi dist(n + 1, 1e17);
    dist[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto x : v)
        {
            ll a = x[0];
            ll b = x[1];
            ll c = x[2];
            if (dist[a] == inf)
                continue;
            dist[b] = min(dist[b], dist[a] + c); // relaxing
            if (dist[b] < ninf)
                dist[b] = ninf;
        }
    }
    for (int i = 1; i < n; i++)
        for (auto x : v)
        {
            // we do this n-1 times to propagate effect of ninf to every possible node
            // because as the node dist can go smaller and smaller hence all nodes conncted will
            // also decrease
            if (dist[x[0]] == inf)
                continue;
            if (dist[x[1]] > dist[x[0]] + x[2])
            {
                dist[x[1]] = ninf;
            }
        }
    if (dist[n] == ninf)
    {
        cout << -1 << endl;
        return;
    }
    cout << -1 * dist[n] << endl;
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