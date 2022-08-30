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

const int Mod = 1e9 + 7;
int block;
struct qry
{
    int l, r, ind;
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    ll cnt[1000007];
    block = sqrt(n);
    sort(a.begin(), a.end());
    int ind = 1;
    map<ll, ll> mp;
    for (auto x : a)
    {
        if (mp.count(x) == 0)
        {
            mp[x] = ind;
            ind++;
        }
    }
    qry qq[q + 1];
    for (int i = 0; i < n; i++)
        a[i] = mp[b[i]];
    for (int i = 0; i < q; i++)
    {
        cin >> qq[i].l >> qq[i].r;
        qq[i].l--;
        qq[i].r--;
        qq[i].ind = i;
    }
    sort(qq, qq + q, [](qry a, qry b)
         {
        if(a.l/block==b.l/block)
         return a.r<b.r;
        return a.l/block<b.l/block; });
    int cl = 0, cr = 0;
    vi answ(q);
    ll ans = 0;
    for (int i = 0; i < q; i++)
    {
        int lft = qq[i].l, ryt = qq[i].r;
        while (cl < lft)
        {
            cnt[a[cl]]--;
            if (cnt[a[cl]] == 0)
                ans--;
            cl++;
        }
        while (cl > lft)
        {
            cnt[a[cl - 1]]++;
            if (cnt[a[cl - 1]] == 1)
                ans++;
            cl--;
        }
        while (cr <= ryt)
        {
            cnt[a[cr]]++;
            if (cnt[a[cr]] == 1)
                ans++;
            cr++;
        }
        while (cr > ryt + 1)
        {
            cnt[a[cr - 1]]--;
            if (cnt[a[cr - 1]] == 0)
                ans--;
            cr--;
        }
        answ[qq[i].ind] = ans;
    }
    for (auto x : answ)
        cout << x << endl;
}
int main()
{
    FAST_IO
    ll t = 1;
    // cin>>t;

    while (t--)
    {
        solve();
    }
    return 0;
}