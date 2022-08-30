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
ll a, b;
ll fun(ll n)
{
    ll c = 0;
    while (n >= 10)
    {
        n /= 10;
        c++;
    }
    a = n;
    return c + 1;
}
void solve()
{
    ll x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    if (x1 > x2)
    {
        //get no of digits
        ll nx1 = fun(x1);
        ll fx1 = a;
        ll nx2 = fun(x2);
        ll fx2 = a;
        //cout << fx1 << " " << fx2 << endl;
        if (p1 > p2)
        {
            cout << ">\n";
            return;
        }
        //check for equal also
        if (nx1 + p1 > nx2 + p2)
        {
            cout << ">\n";
            return;
        }
        else if (nx1 + p1 == nx2 + p2)
        {
            if (x1 % x2 == 0 and ((x1 / x2) % 10 == 0))
            {
                // ll x = x2 / x1;
                // cout << x << endl;
                cout << "=\n";
            }
            else
            {
                //compare first digits
                if (fx1 > fx2)
                    cout << ">\n";
                else
                    cout << "<\n";
            }
        }
        else
            cout << "<\n";
    }
    else if (x2 > x1)
    {
        ll nx1 = fun(x1);
        ll fx1 = a;
        ll nx2 = fun(x2);
        ll fx2 = a;
        //cout << fx1 << " " << fx2 << endl;
        if (p2 > p1)
        {
            cout << "<\n";
            return;
        }
        //check for equal also
        if (nx1 + p1 > nx2 + p2)
        {
            cout << ">\n";
            return;
        }
        else if (nx1 + p1 == nx2 + p2)
        {
            if (x2 % x1 == 0 and ((x2 / x1) % 10 == 0))
            {
                cout << "=\n";
            }
            else
            {
                //compare first digits
                if (fx1 > fx2)
                    cout << ">\n";
                else
                    cout << "<\n";
            }
        }
        else
            cout << "<\n";
    }
    else
    {
        if (p1 > p2)
            cout << ">\n";
        else if (p1 < p2)
            cout << "<\n";
        else
            cout << "=\n";
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