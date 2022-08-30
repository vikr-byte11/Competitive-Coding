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
vector<pii> adj[2000005];
vi routes(2000005, 0);
vi f_mn(2000005);
vi f_mx(2000005);
vi cost(2000005, 1e17);
void solve()
{
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    cost[1] = 0;
    routes[1] = 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        if (cost[x.second] < x.first)
            continue;
        for (auto c : adj[x.second])
        {
            if (cost[c.first] < cost[x.second] + c.second)
                continue;
            if (cost[c.first] == cost[x.second] + c.second)
            {
                routes[c.first] += routes[x.second];
                routes[c.first] %= md;
                f_mn[c.first] = min(f_mn[x.second] + 1, f_mn[c.first]);
                f_mx[c.first] = max(f_mx[x.second] + 1, f_mx[c.first]);
            }
            else
            {
                cost[c.first] = cost[x.second] + c.second;
                routes[c.first] = routes[x.second];
                f_mn[c.first] = f_mn[x.second] + 1;
                f_mx[c.first] = f_mx[x.second] + 1;
                pq.push({cost[c.first], c.first});
            }
        }
    }
    cout << cost[n] << " " << routes[n] << " " << f_mn[n] << " " << f_mx[n];
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