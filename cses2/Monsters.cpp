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
// Vikram1234@
int n, m;
vector<pair<int, int>> monster;
vector<vector<int>> g;
map<pair<int, int>, pair<int, int>> par_mp;
pair<int, int> si, se;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y, int timer)
{
    if (x < 0 or y < 0 or x >= n or y >= m)
    {
        return false;
    }
    if (g[x][y] <= timer)
    {
        return false;
    }
    return true;
}

bool isExcape(int x, int y, int timer)
{
    if (g[x][y] <= timer)
        return false;
    if (x == 0 or y == 0 or
        x == n - 1 or y == m - 1)
        return true;
    return false;
}

bool bfs_escape()
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(si, 0));
    par_mp[si] = {-1, -1};
    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();
        for (auto mv : moves)
        {
            int tx = cx + mv.first;
            int ty = cy + mv.second;
            if (isExcape(tx, ty, timer))
            {
                par_mp[{tx, ty}] = {cx, cy};
                se = {tx, ty};
                return true;
            }
            if (isValid(tx, ty, timer))
            {
                par_mp[{tx, ty}] = {cx, cy};
                g[tx][ty] = timer;
                q.push({{tx, ty}, timer});
            }
        }
    }
    return false;
}

void preprocess_lava_flow()
{
    queue<pair<pair<int, int>, int>> q;
    for (auto m : monster)
    {
        q.push(make_pair(m, 0));
    }
    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();
        for (auto mv : moves)
        {
            int tx = cx + mv.first;
            int ty = cy + mv.second;
            if (isValid(tx, ty, timer))
            {
                g[tx][ty] = timer;
                q.push({{tx, ty}, timer});
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; ++i)
    {
        g[i].resize(m);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            g[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                g[i][j] = 0;
            }
            else if (c == 'M')
            {
                g[i][j] = 0;

                monster.push_back({i, j});
            }
            else if (c == 'A')
            {
                g[i][j] = 0;
                si = {i, j};
            }
            else
            {
                g[i][j] = INT_MAX;
            }
        }
    }
    if (si.first == 0 or si.second == 0 or si.first == n - 1 or si.second == m - 1)
    {
        cout << "YES" << endl;
        cout << 0;
        return 0;
    }
    preprocess_lava_flow();

    if (!bfs_escape())
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    pair<int, int> tmp = se;
    pair<int, int> tmp1 = par_mp[se];
    pair<int, int> ed = {-1, -1};
    vector<char> ans;
    while (tmp1 != ed)
    {

        if ((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
        {
            ans.push_back('R');
        }
        if ((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
        {
            ans.push_back('L');
        }
        if ((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
        {
            ans.push_back('D');
        }
        if ((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
        {
            ans.push_back('U');
        }
        tmp = par_mp[tmp];
        tmp1 = par_mp[tmp];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto c : ans)
    {
        cout << c;
    }
}