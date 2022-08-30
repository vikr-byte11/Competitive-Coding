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
void solve()
{
  static int x = 1;
  string req, prod;
  cin >> req >> prod;
  if (req == prod)
  {
    cout << "Case #" << x << ": " << 0 << endl;
    return;
  }
  if (prod.size() <= req.size())
  {
    cout << "Case #" << x << ": "
         << "IMPOSSIBLE" << endl;
    return;
  }
  int i = 0, j = 0;
  ll ans = 0;
  while (i < req.size() and j < prod.size())
  {

    if (req[i] == prod[j])
    {
      i++;
      j++;
      continue;
    }
    ans++;
    j++;
  }
  if (i != (int)req.size())
  {
    cout << "Case #" << x << ": "
         << "IMPOSSIBLE" << endl;
  }
  else
  {
    ans += (prod.size() - j);
    cout << "Case #" << x << ": " << ans << endl;
  }
  x++;
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