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
    ll n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    //store diff b/w every character
    vi diff(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[i] == b[i])
                diff[i + 1] = 1;
            else
                diff[i + 1] = 0;
        }
        else
        {
            ll td1 = 0, td2 = 0;
            if (a[i] > a[i - 1])
            {
                ll x1 = (a[i] - 'a') - 25;
                x1 += (a[i - 1] - 'a');
                x1++;
                td1 = x1;
            }
            else
            {
                td1 = (a[i - 1] - 'a') - (a[i] - 'a');
            }
            if (b[i] > b[i - 1])
            {
                ll x1 = (b[i] - 'a') - 25;
                x1 += (b[i - 1] - 'a');
                x1++;
                td2 = x1;
            }
            else
            {
                td2 = (b[i - 1] - 'a') - (b[i] - 'a');
            }
            if (td1 == td2)
                diff[i + 1] = 1;
            else
                diff[i + 1] = 0;
        }
    }
    //op(diff);
    for (int i = 1; i <= n; i++)
        diff[i] += diff[i - 1];
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << "Yes\n";
            continue;
        }
        if (diff[r] - diff[l] == (r - l))
            cout << "Yes\n";
        else
            cout << "No\n";
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