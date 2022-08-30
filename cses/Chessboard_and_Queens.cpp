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
vector<vector<char>> grid(8, vector<char>(8));
vector<vector<int>> result;
int c = 0;
bool issafe(int i, int j)
{
    if (grid[i][j] == '*')
        return false;
    //check the col
    for (int k = 0; k < i; k++)
        if (grid[k][j] == 'A')
            return false;
    //ld
    int li = i, lj = j;
    while (li >= 0 and lj >= 0)
    {
        if (grid[li][lj] == 'A')
            return false;
        li--;
        lj--;
    }
    li = i, lj = j;
    while (li >= 0 and lj < 8)
    {
        if (grid[li][lj] == 'A')
            return false;
        li--;
        lj++;
    }
    return true;
}
void fun(int row)
{
    if (row == 8)
    {
        c++;
        vector<int> temp;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if (grid[i][j] == 'A')
                    temp.push_back(j + 1);
            }
        result.push_back(temp);
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (issafe(row, i))
        {
            grid[row][i] = 'A';
            fun(row + 1);
            grid[row][i] = '.';
        }
    }
}
void solve()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> grid[i][j];
    fun(0);
    cout << c << endl;
    for (auto x : result)
    {
        for (auto y : x)
            cout << y;
        cout << endl;
    }
    //this is n queen
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