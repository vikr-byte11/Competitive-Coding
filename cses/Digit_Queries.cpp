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
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef map<int, int> mii;

const ll md = 1e9 + 7;
// &*!=
// ()@
//Vikram1234@
void solve()
{
    ll q;
    cin >> q;
    vi pten(19, 1);
    for (int i = 1; i <= 18; i++)
        pten[i] = pten[i - 1] * 10;
    while (q--)
    {
        //cout << q << endl;
        ll k;
        cin >> k;
        ll beforedig = 0, sd = 0, noofdig = 0;
        for (int i = 1; i <= 18; i++)
        {

            sd += (pten[i] - pten[i - 1]) * i;
            if (sd >= k)
            {
                //this is the block of digit where number lies
                //i.e. 1 digit,2 digit or ....
                noofdig = i;
                break;
            }
            beforedig += (pten[i] - pten[i - 1]) * i;
        }
        ll lo = pten[noofdig - 1];
        ll hi = pten[noofdig] - 1;
        ll bv = 0, bs;
        while (hi >= lo)
        {
            ll mid = lo + (hi - lo) / 2;
            //find noofdig for starting of this mid
            ll c = beforedig + 1 + (mid - pten[noofdig - 1]) * noofdig;
            if (c <= k)
            {
                if (mid > bv)
                {
                    bv = mid;
                    bs = c;
                }
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        //now we have number whose starting is closest to k
        string number = to_string(bv);
        //106 107 108
        //we need 107 so f-s will give us the index
        cout << number[k - bs] << endl;
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