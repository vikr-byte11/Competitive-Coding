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
ll tot, mx;
ll parent[2000005];
ll rnk[2000005];
ll len[2000005];
ll findpar(ll node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findpar(parent[node]);
}
void unione(ll x, ll y)
{
    ll u = findpar(x);
    ll v = findpar(y);
    if (rnk[u] < rnk[v])
    {
        len[v] += len[u];
        mx = max(len[v], mx);
        parent[u] = v;
    }
    else if (rnk[v] < rnk[u])
    {
        len[u] += len[v];
        mx = max(len[u], mx);
        parent[v] = u;
    }
    else
    {
        len[u] += len[v];
        mx = max(len[u], mx);
        parent[v] = u;
        rnk[u]++;
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
        len[i] = 1;
    }
    tot = n;
    mx = 1;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        ll a = findpar(x);
        ll b = findpar(y);
        if (a != b)
        {
            unione(x, y);
            tot--;
        }
        else
            mx = max(len[a], mx);
        cout << tot << " " << mx << endl;
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