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
    ll n, k;
    cin >> n >> k;
    vi v(n);
    ip(v);
    multiset<pii> lft, ryt;
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << 0 << endl;
        return;
    }
    if (k == 2)
    {

        for (int i = 1; i < n; i++)
            cout << abs(v[i - 1] - v[i]) << " ";
        return;
    }
    ll ls = 0, rs = 0;
    vpii vf(k);
    for (int i = 0; i < k; i++)
        vf[i] = {v[i], i};
    srt(vf);
    for (int i = 0; i < k / 2 + k % 2; i++)
    {
        lft.insert(vf[i]);
        ls += vf[i].first;
    }
    for (int i = k / 2 + k % 2; i < k; i++)
    {
        ryt.insert(vf[i]);
        rs += vf[i].first;
    }

    ll median = lft.rbegin()->first;
    cout << median * lft.size() - ls + rs - median * ryt.size() << " ";
    for (int j = 1; j + k - 1 < n; j++)
    {
        //remove j-1th value;
        if (lft.count({v[j - 1], j - 1}))
        {
            ls -= v[j - 1];
            lft.erase({v[j - 1], j - 1});
        }
        else
        {
            rs -= v[j - 1];
            ryt.erase({v[j - 1], j - 1});
        }
        //now insertion
        if (*(lft.rbegin()) < make_pair(v[k - 1 + j], k - 1 + j))
        {
            rs += v[k - 1 + j];
            ryt.insert({v[j + k - 1], j + k - 1});
        }
        else
        {
            ls += v[k - 1 + j];
            lft.insert({v[j + k - 1], j + k - 1});
        }
        //now maintain size
        while (lft.size() < k / 2 + k % 2)
        {
            auto x = *(ryt.begin());
            lft.insert(x);
            ls += x.first;
            rs -= x.first;
            ryt.erase(x);
        }
        while (lft.size() > k / 2 + k % 2)
        {
            auto x = *(lft.rbegin());
            ryt.insert(x);
            lft.erase(x);
            rs += x.first;
            ls -= x.first;
        }

        median = lft.rbegin()->first;
        //we have median of this window
        cout << median * lft.size() - ls + rs - median * ryt.size() << " ";
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