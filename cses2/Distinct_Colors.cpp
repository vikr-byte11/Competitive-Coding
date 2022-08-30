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
// Vikram1234@
vi adj[200005];
ll color[200005];
ll nodeidx[200005];
ll arr[200005];
ll subsize[200005];
ll ans[200005];
ll timer = 0;
ll n;
ll answer = 0;
ll freq[200005];
ll block;
void dfs(ll src, ll par)
{
    subsize[src] = 1;
    nodeidx[src] = ++timer;
    arr[nodeidx[src]] = color[src];
    for (auto x : adj[src])
    {
        if (x == par)
            continue;
        dfs(x, src);
        subsize[src] += subsize[x];
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    // compress color
    ll tmp[200005];
    for (int i = 1; i <= n; i++)
        tmp[i] = color[i];
    // color[0] = INT_MAX;
    map<ll, ll> mp;
    sort(color, color + n + 1);
    ll idx = 1;
    for (int i = 1; i <= n; i++)
    {
        if (mp.count(color[i]) == 0)
        {
            mp[color[i]] = idx;
            idx++;
        }
    }
    for (int i = 1; i <= n; i++)
        color[i] = mp[tmp[i]];
    for (int i = 2; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1);
    // mo's algo + flatten tree
    block = sqrt(n);
    vector<vector<ll>> qry;
    for (int i = 1; i <= n; i++)
        qry.push_back({nodeidx[i], nodeidx[i] + subsize[i] - 1, i});
    sort(qry.begin(), qry.end(), [](vi a, vi b)
         {
             if (a[0] / block != b[0] / block)
                 return a[0] / block < b[0] / block;
             return a[1] / block < b[1] / block; });
    // now mo's begin
    int cl = 1, cr = 1;
    // cl ke peeche wale sare removed hai
    // cr k peeche wale sare added h
    // cl added nhi h aur cr added mhi h
    for (int i = 0; i < n; i++)
    {
        int l = qry[i][0];
        int r = qry[i][1];
        while (cl < l)
        {
            // remove
            freq[arr[cl]]--;
            if (freq[arr[cl]] == 0)
                answer--;
            cl++;
        }
        while (cl > l)
        {
            // add
            freq[arr[cl - 1]]++;
            if (freq[arr[cl - 1]] == 1)
                answer++;
            cl--;
        }
        while (cr <= r)
        {
            freq[arr[cr]]++;
            if (freq[arr[cr]] == 1)
                answer++;
            cr++;
        }
        while (cr > r + 1)
        {
            // remove
            freq[arr[cr - 1]]--;
            if (freq[arr[cr - 1]] == 0)
                answer--;
            cr--;
        }
        ans[qry[i][2]] = answer;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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