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
ll vis[2001][2001];
const ll md = 1e9 + 7;
// &*!=
// ()@
//Vikram1234@
bool isvalid(int x, int y, vector<vector<char>> &grid)
{
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
        return false;
    if (vis[x][y] || grid[x][y] == '#')
        return false;
    return true;
}
void solve()
{
    memset(vis, 0, sizeof(vis));
    // above floor there shoud be wall
    ll n, m, srcx, srcy, dstx, dsty;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<char>> dir(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                srcx = i;
                srcy = j;
            }
            if (grid[i][j] == 'B')
            {
                dstx = i;
                dsty = j;
            }
        }
    //shortest in length mens bfs
    bool f = false;
    map<pair<int, int>, pair<pair<int, int>, char>> mpp;
    vis[srcx][srcy] = 1;
    queue<pair<int, int>> q;
    q.push({srcx, srcy});
    string res = "";
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        int a = x.first;
        int b = x.second;
        if (grid[a][b] == 'B')
        {
            f = true;
            //create answer and break;
            auto end = mp(a, b);
            while (1)
            {
                res += mpp[end].second;
                end = mpp[end].first;
                if (end.first == srcx and end.second == srcy)
                    break;
            }
            break;
        }
        if (isvalid(a - 1, b, grid))
        {
            vis[a - 1][b] = 1;
            q.push({a - 1, b});
            mpp[{a - 1, b}] = {{a, b}, 'U'};
        }
        if (isvalid(a + 1, b, grid))
        {
            vis[a + 1][b] = 1;
            q.push({a + 1, b});
            mpp[{a + 1, b}] = {{a, b}, 'D'};
        }
        if (isvalid(a, b + 1, grid))
        {
            vis[a][b + 1] = 1;
            q.push({a, b + 1});
            mpp[{a, b + 1}] = {{a, b}, 'R'};
        }
        if (isvalid(a, b - 1, grid))
        {
            vis[a][b - 1] = 1;
            q.push({a, b - 1});
            mpp[{a, b - 1}] = {{a, b}, 'L'};
        }
    }
    if (!f)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << res.size() << endl;
    rev(res);
    for (auto x : res)
        cout << x;
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