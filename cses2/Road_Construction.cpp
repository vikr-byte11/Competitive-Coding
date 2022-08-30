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
ll parent[200005];
ll rnk[200005];
ll comp[200005];
ll mx, tot;
ll fnd(ll x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = fnd(parent[x]);
}
void un(ll a, ll b)
{
    if (rnk[a] < rnk[b])
    {
        comp[b] += comp[a];
        parent[a] = b;
        mx = max(mx, comp[b]);
        tot--;
    }

    else if (rnk[a] > rnk[b])
    {
        comp[a] += comp[b];
        mx = max(mx, comp[a]);
        parent[b] = a;
        tot--;
    }
    else
    {
        comp[a] += comp[b];
        parent[b] = a;
        mx = max(mx, comp[a]);
        tot--;
    }
}
void solve()
{
    mx = 0, tot = 0;
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v;
    tot = n;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
        comp[i] = 1;
    }
    for (auto e : v)
    {
        ll a = fnd(e.first);
        ll b = fnd(e.second);
        if (a != b)
            un(a, b);
        cout << tot << " " << mx << endl;
    }
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