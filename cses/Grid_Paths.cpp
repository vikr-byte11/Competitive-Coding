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
int dp[20][20];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
#define right 0
#define left 1
#define down 2
#define up 3
bool isvalid(int x)
{
    if (x < 0)
        return false;
    if (x >= 7)
        return false;
    return true;
}
int fun(int idx, string s, int x, int y)
{
    if (idx == s.length())
    {
        return (x == 6 and y == 0);
    }
    if (x == 6 and y == 0)
        return 0;

    if (dp[x][y])
        return 0;
    vector<int> visited(4, -1);
    for (int i = 0; i < 4; i++)
    {
        if (isvalid(x + dx[i]) and isvalid(y + dy[i]))
            visited[i] = dp[x + dx[i]][y + dy[i]];
    }
    if (!visited[down] && !visited[up] && visited[right] && visited[left])
        return 0;
    if (visited[down] && visited[up] && !visited[right] && !visited[left])
        return 0;
    if (isvalid(x - 1) and isvalid(y + 1) and dp[x - 1][y + 1] == 1)
        if (!visited[right] and !visited[up])
            return 0;
    if (isvalid(x + 1) and isvalid(y + 1) and dp[x + 1][y + 1] == 1)
        if (!visited[right] and !visited[down])
            return 0;
    if (isvalid(x - 1) and isvalid(y - 1) and dp[x - 1][y - 1] == 1)
        if (!visited[left] and !visited[up])
            return 0;
    if (isvalid(x + 1) and isvalid(y - 1) and dp[x + 1][y - 1] == 1)
        if (!visited[down] and !visited[left])
            return 0;
    dp[x][y] = 1;
    int nop = 0;
    if (s[idx] == '?')
    {
        for (int i = 0; i < 4; i++)
        {
            if (isvalid(x + dx[i]) and isvalid(y + dy[i]))
                nop += fun(idx + 1, s, x + dx[i], y + dy[i]);
        }
    }
    else if (s[idx] == 'L' and y - 1 >= 0)
        nop = fun(idx + 1, s, x, y - 1);

    else if (s[idx] == 'R' and y + 1 < 7)
        nop = fun(idx + 1, s, x, y + 1);

    else if (s[idx] == 'U' and x - 1 >= 0)
        nop = fun(idx + 1, s, x - 1, y);
    else if (s[idx] == 'D' and x + 1 < 7)
        nop = fun(idx + 1, s, x + 1, y);
    dp[x][y] = 0;
    return nop;
}
void solve()
{
    string s;
    cin >> s;
    memset(dp, 0, sizeof(dp));
    cout << fun(0, s, 0, 0);
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