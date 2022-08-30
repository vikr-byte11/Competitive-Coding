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
void tbuild(vi &hotel, int ns, int ne, int tnode, vi &stree)
{
    if (ns == ne)
    {
        stree[tnode] = hotel[ns];
        return;
    }
    ll mid = (ns + ne) / 2;
    tbuild(hotel, ns, mid, 2 * tnode, stree);
    tbuild(hotel, mid + 1, ne, 2 * tnode + 1, stree);
    stree[tnode] = max(stree[2 * tnode], stree[2 * tnode + 1]);
}
void query(vi &stree, int ns, int ne, int tnode, int val)
{
    if (ns == ne)
    {
        cout << ns << " ";
        stree[tnode] -= val;
        return;
    }
    ll mid = (ns + ne) / 2;
    if (stree[2 * tnode] >= val)
        query(stree, ns, mid, 2 * tnode, val);
    else
        query(stree, mid + 1, ne, 2 * tnode + 1, val);
    stree[tnode] = max(stree[2 * tnode], stree[2 * tnode + 1]);
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vi hotels(n + 1), stree(4 * n + 2);
    vi groups(m + 1);
    //fucking segment tree
    for (int i = 1; i <= n; i++)
        cin >> hotels[i];
    for (int i = 1; i <= m; i++)
        cin >> groups[i];
    tbuild(hotels, 1, n, 1, stree);
    for (int i = 1; i <= m; i++)
    {
        if (stree[1] < groups[i])
            cout << 0 << " ";
        else
            query(stree, 1, n, 1, groups[i]);
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