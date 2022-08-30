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
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int Mod = 1e9 + 7;
void solve()
{
    ll n, m, srcx, srcy, dstx, dsty;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    string res = "";
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
    map<pair<int, int>, pair<pair<int, int>, char>> mp;
    // key->x,y
    // value->({parentof (x,y) and direction which we took from parent to get to x,y})
    // n nodes in path will have n-1 directions
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({srcx, srcy});
    vis[srcx][srcy] = 1;
    int f = 0;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        int a = x.first, b = x.second;
        if (grid[a][b] == 'B')
        {
            f = 1;
            while (1)
            {
                res += (mp[{a, b}].second);
                int tmp = a;
                a = mp[{a, b}].first.first;
                b = mp[{tmp, b}].first.second;
                if (a == srcx and b == srcy)
                    break;
            }
            // create ans and go
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i], ny = b + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] == 1 || grid[nx][ny] == '#')
                continue;
            vis[nx][ny] = 1;
            char dir;
            if (i == 0)
                dir = 'D';
            if (i == 1)
                dir = 'U';
            if (i == 2)
                dir = 'R';
            if (i == 3)
                dir = 'L';
            mp[{nx, ny}] = {{a, b}, dir};
            q.push({nx, ny});
        }
    }
    if (!f)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    cout << res << endl;
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