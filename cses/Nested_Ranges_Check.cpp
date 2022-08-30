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
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(3));
    fo(i, n)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end(), [](vector<ll> a, vector<ll> b)
         {
             if (a[0] == b[0])
                 return a[1] > b[1];
             return a[0] < b[0];
         });
    vi v1(n, 0), v2(n, 0);
    ll mxr = 0;
    for (int i = 0; i < n; i++)
    {
        //this for wether this interval is contained or not
        //now curr start>prev start
        if (v[i][1] <= mxr)
            v1[v[i][2]] = 1;
        mxr = max(mxr, v[i][1]);
    }
    ll mnr = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i][1] >= mnr)
            v2[v[i][2]] = 1;
        mnr = min(mnr, v[i][1]);
    }
    op(v2);
    op(v1);
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