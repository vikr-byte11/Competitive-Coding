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
#define FAST_IO            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define ip(v)       \
  for (auto &x : v) \
  cin >> x
#define op(v)         \
  for (auto x : v)    \
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
ll dp[10000006];
ll fun(int idx, vector<vector<ll>> &v)
{
  if (idx >= v.size() || idx < 0)
    return 0;
  if (dp[idx] != -1)
    return dp[idx];
  ll op1 = fun(idx + 1, v);
  ll ni = -1;
  ll lo = idx + 1, hi = v.size() - 1;
  while (lo <= hi)
  {
    ll mid = lo + (hi - lo) / 2;
    if (v[mid][0] > v[idx][1])
    {
      ni = mid;
      hi = mid - 1;
    }
    else
      lo = mid + 1;
  }
  ll op2 = v[idx][2] + fun(ni, v);
  return dp[idx] = max(op1, op2);
}
void solve()
{
  ll n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  vector<vector<ll>> vp;
  for (int i = 0; i < n; i++)
  {
    ll x, y, z;
    cin >> x >> y >> z;
    vp.push_back({x, y, z});
  }
  srt(vp);
  cout << fun(0, vp) << endl;
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