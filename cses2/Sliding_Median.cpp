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
void solve()
{
    ll n, k;
    cin >> n >> k;
    vi v(n);
    ip(v);
    if (k == 1)
    {
        op(v);
        return;
    }
    if (k == 2)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << min(v[i], v[i + 1]) << " ";
        }
        return;
    }
    multiset<pair<ll, int>> lft, ryt;
    int i = 0, j = 0;
    while (j < n)
    {
        //push the jth ele in suitabl set
        if (lft.size() == 0)
            lft.insert({v[j], j});
        else
        {
            auto x = *(lft.rbegin());
            if (x.first > v[j])
                lft.insert({v[j], j});
            else
                ryt.insert({v[j], j});
        }
        if (j - i + 1 < k)
        {
            j++;
            continue;
        }
        else
        {
            //here we are with ws = k
            //first adjust the sizes of sets
            //lft size must be k/2+k%2
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
            //get answer
            auto ans = *(lft.rbegin());
            cout << ans.first << " ";
            //now remove ith ele
            auto x = lft.find({v[i], i});
            if (x == lft.end())
                ryt.erase({v[i], i});
            else
                lft.erase({v[i], i});
            i++;
            j++;
        }
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