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

const int md = 1e9 + 7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vpii adj[n + 2];
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    vi cost(n + 1, 1e17), route(n + 1, 0), fmn(n + 1), fmx(n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    cost[1] = 0;
    route[1] = 1;
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        ll node = x.second;
        ll c = x.first;
        if (cost[node] < c)
            continue;
        for (auto y : adj[node])
        {
            ll child = y.first;
            ll cc = y.second;
            if (cost[child] > cost[node] + cc)
            {
                route[child] = route[node];
                cost[child] = cost[node] + cc;
                fmn[child] = fmn[node] + 1;
                fmx[child] = fmx[node] + 1;
                pq.push({cost[child], child});
            }
            else if (cost[child] == cost[node] + cc)
            {
                route[child] += route[node];
                route[child] %= md;
                fmn[child] = min(fmn[child], fmn[node] + 1);
                fmx[child] = max(fmx[child], fmx[node] + 1);
            }
        }
    }
    cout << cost[n] << " " << route[n] << " " << fmn[n] << " " << fmx[n];
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