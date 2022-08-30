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

void olve()
{
    ll n, m;
    cin >> n >> m;
    vector<vi> edges;
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }
    int f = 0;
    vi dist(n + 1, 0);
    vi par(n + 1, 0);
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        f = 0;
        for (auto e : edges)
        {
            if (dist[e[0]] == 1e17)
                continue;
            if (dist[e[0]] + e[2] < dist[e[1]])
            {
                dist[e[1]] = dist[e[0]] + e[2];
                par[e[1]] = e[0];
                f = e[1];
            }
        }
    }
    if (!f)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        f = par[f];
    vi cyc;
    for (int x = f;; x = par[x])
    {
        cyc.push_back(x);
        if (x == f and cyc.size() > 1)
            break;
    }
    rev(cyc);
    op(cyc);
}
void soe()
{
    ll l, r, a;
    cin >> l >> r >> a;
    if (l == r)
    {
        cout << (l / a) + (l % a) << endl;
        return;
    }
    ll reml = l % a;
    ll remr = r % a;
    if (l / a == r / a)
    {
        if (remr == 0)
        {
            cout << (l / a) + (a - 1) << endl;
        }
        else
            cout << (r / a) + remr << endl;
        return;
    }
    if (remr == a - 1)
    {
        cout << (r / a) + remr << endl;
        return;
    }
    ll ass = (r / a) - 1;
    cout << ass + a - 1 << endl;
}
void solve()
{
    ll n;
    cin >> n;
    vi anda(2000);
    for (int i = 0; i < 1000; i++)
        anda[i] = i + 1;
    vi vela(n), lelo(n + 1);
    ip(vela);
    mii maaap;
    ll aex = n;
    ll flag = 0, tenu = n - 1;
    while (tenu--)
    {
        maaap.clear();
        for (int i = 0; i < n; ++i)
            maaap[vela[i]] = i + 1;
        if (maaap[aex] != aex)
        {
            int d = aex - maaap[aex];
            if (d < 0)
            {
                flag = 1;
                break;
            }
            reverse(vela.begin(), vela.begin() + aex);
            srt(anda);
            reverse(vela.begin(), vela.begin() + (d));
            rev(anda);
            reverse(vela.begin() + d, vela.begin() + aex);

            lelo[aex] = (aex - d) % aex;
        }
        else
            lelo[aex] = 0;
        --aex;
    }
    if (flag == 1)
        cout << "-1";
    else
    {
        for (int i = 1; i <= n; ++i)
            cout << lelo[i] << " ";
        cout << endl;
    }
}
int main()
{

    FAST_IO
    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
