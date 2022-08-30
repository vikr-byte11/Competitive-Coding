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

const int Mod = 1e9 + 2;
// &*!=
// ()@
//Vikram1234@
ll dp[20][2][2][2];
ll fun(string s, int lz, int n, int tight, int p)
{
    //base case later
    if (n == 0)
        return 1;
    if (dp[n][p][lz][tight] != -1)
        return dp[n][p][lz][tight];
    if (lz) //no. not started
    {
        ll op1 = fun(s, 1, n - 1, 0, 1);
        ll op2 = 0;
        ll ub = tight ? s[s.length() - n] - '0' : 9;
        if (p) //only odd numbers can come
        {
            for (int i = 1; i <= 9 and i <= ub; i += 2)
            {
                op2 += fun(s, 0, n - 1, tight & (i == ub), 1 - p);
            }
        }
        else
        {
            //only even can come
            for (int i = 2; i <= 9 and i <= ub; i += 2)
            {
                op2 += fun(s, 0, n - 1, tight & (i == ub), 1 - p);
            }
        }
        return dp[n][p][lz][tight] = op1 + op2;
    }
    //no is started
    ll op2 = 0;
    ll ub = tight ? s[s.length() - n] - '0' : 9;
    if (p) //only odd numbers can come
    {
        for (int i = 1; i <= 9 and i <= ub; i += 2)
        {
            op2 += fun(s, 0, n - 1, tight & (i == ub), 1 - p);
        }
    }
    else
    {
        //only even can come
        for (int i = 0; i <= 9 and i <= ub; i += 2)
        {
            op2 += fun(s, 0, n - 1, tight & (i == ub), 1 - p);
        }
    }
    return dp[n][p][lz][tight] = op2;
}
void solve()
{
    static int bh = 0;
    bh++;
    ll a, b;
    cin >> a >> b;
    string l, r;
    l = to_string(a - 1);
    r = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll a1 = fun(l, 1, l.size(), 1, 1);
    memset(dp, -1, sizeof(dp));
    ll a2 = fun(r, 1, r.size(), 1, 1);
    ll ans = a2 - a1;
    cout << "Case #" << bh << ": "
         << ans << endl;
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