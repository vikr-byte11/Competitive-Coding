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
ll kmp[2001];
ll pre[2001];
void k_mp(string s)
{
    ll n = s.length();
    pre[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = pre[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pre[j - 1];
        if (s[i] == s[j]) //comparing nxt char bcoz of indexing
            j++;
        pre[i] = j;
    }
}
ll dp[1001][101];
ll fun(int i, int n, int j, string s)
{
    if (i == n)
    {
        if (j == (int)s.size())
            return 1;
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (j == (int)s.size())
        return (26 * fun(i + 1, n, j, s)) % md;
    ll ans = 0;
    ll t;
    //keep every character
    for (int k = 0; k < 26; k++)
    {
        t = j;
        while (true)
        {
            if (k == s[t] - 'A')
            {
                t++;
                break;
            }
            else if (t)
            {
                t = pre[t - 1];
            }
            else
                break;
        }
        ans += fun(i + 1, n, t, s);
        ans %= md;
    }
    return dp[i][j] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    ll n;
    cin >> n;
    string s;
    cin >> s;
    k_mp(s);
    // for (int i = 0; i < s.length(); i++)
    //     cout << pre[i] << " ";
    cout << fun(0, n, 0, s);
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