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
vector<vector<ll>> ans;
ll k;
void fun(int idx, vi &v, ll n, vi &tmp)
{
    if (idx >= v.size())
    {
        ans.push_back(tmp);
        k--;
        return;
    }
    //op for this place
    for (int i = 0; i < n; i++)
    {
        if (k == 0)
            return;
        if (v[i] != -1)
        {
            if (idx >= 2)
            {
                if (tmp[idx - 1] + tmp[idx - 2] != v[i])
                {
                    tmp.push_back(v[i]);
                    ll x = v[i];
                    v[i] = -1;
                    fun(idx + 1, v, n, tmp);
                    v[i] = x;
                    tmp.pop_back();
                }
            }
            else
            {
                tmp.push_back(v[i]);
                ll x = v[i];
                v[i] = -1;
                fun(idx + 1, v, n, tmp);
                v[i] = x;
                tmp.pop_back();
            }
        }
    }
}
void solve()
{
    ans.clear();

    ll n;
    cin >> n;
    k = n;
    vi v(n);
    for (int i = 1; i <= n; i++)
        v[i - 1] = i;
    vector<ll> tmp;
    fun(0, v, n, tmp);
    for (int i = 0; i < n; i++)
    {
        for (auto x : ans[i])
            cout << x << " ";
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