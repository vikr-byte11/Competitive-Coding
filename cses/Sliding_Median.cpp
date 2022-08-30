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
        op(v);
        return;
    }
    if (k == 2)
    {
        for (int i = 1; i < n; i++)
            cout << min(v[i - 1], v[i]) << " ";
        return;
    }
    vpii vf(k);
    for (int i = 0; i < k; i++)
        vf[i] = {v[i], i};
    srt(vf);
    for (int i = 0; i < k / 2 + k % 2; i++)
        lft.insert(vf[i]);
    for (int i = k / 2 + k % 2; i < k; i++)
        ryt.insert(vf[i]);
    cout << lft.rbegin()->first << " ";
    for (int j = 1; j + k - 1 < n; j++)
    {
        //remove j-1th value;
        if (lft.count({v[j - 1], j - 1}))
            lft.erase({v[j - 1], j - 1});
        else
            ryt.erase({v[j - 1], j - 1});
        //now insertion
        if (*(lft.rbegin()) < make_pair(v[k - 1 + j], k - 1 + j))
            ryt.insert({v[j + k - 1], j + k - 1});
        else
            lft.insert({v[j + k - 1], j + k - 1});
        //now maintain size
        while (lft.size() < k / 2 + k % 2)
        {
            auto x = *(ryt.begin());
            lft.insert(x);
            ryt.erase(x);
        }
        while (lft.size() > k / 2 + k % 2)
        {
            auto x = *(lft.rbegin());
            ryt.insert(x);
            lft.erase(x);
        }
        cout << lft.rbegin()->first << " ";
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