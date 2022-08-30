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
#define px pair<ll, pair<ll, pair<ll, ll>>>;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
typedef map<ll, ll> mii;
vector<pair<ll, ll>> moves = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
const ll md = 1e9 + 7;
bool isvalid(ll x, ll y, vector<vector<ll>> &grid)
{
    if (x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size())
        return false;
    return true;
}
// &*!=
// ()@
//Vikram1234@
pair<ll, pair<ll, vpii>> bfs(int i, int j, vector<vector<ll>> &grid, vector<vector<ll>> &value)
{
    priority_queue<pair<ll, pair<ll, pair<ll, ll>>>, vector<pair<ll, pair<ll, pair<ll, ll>>>>,
                   greater<pair<ll, pair<ll, pair<ll, ll>>>>>
        pq;
    if (grid[i][j] == 2)
        pq.push({1, {value[i][j], {i, j}}});
    else
        pq.push({0, {value[i][j], {i, j}}});
    vector<vector<ll>> dist(grid.size(), vector<ll>(grid[0].size(), INT_MAX));
    vector<vector<ll>> vis(grid.size(), vector<ll>(grid[0].size(), 0));
    map<pair<ll, ll>, pair<ll, ll>> maap;
    dist[i][j] = value[i][j];
    vis[i][j] = 1;
    maap[{i, j}] = {-1, -1};
    //cout << pq.top().second.first << endl;
    while (!pq.empty())
    {
        auto x = pq.top();
        ll a = x.second.second.first;
        ll b = x.second.second.second;
        ll v = x.second.first;
        //cout << a << " " << b << endl;
        pq.pop();
        if (b == grid[0].size() - 1)
        {
            vpii tmp;
            auto g = make_pair(a, b);
            while (1)
            {
                tmp.push_back({g.first, g.second});
                g = maap[g];
                if (g.first == -1 and g.second == -1)
                    break;
            }
            return {x.first, {v, tmp}};
        }
        for (auto mv : moves)
        {
            ll dx = mv.first;
            ll dy = mv.second;
            ll nx = a + dx;
            ll ny = b + dy;
            if (isvalid(nx, ny, grid))
            {
                if (dist[nx][ny] > v + value[nx][ny] and !vis[nx][ny])
                {
                    dist[nx][ny] = v + value[nx][ny];
                    vis[nx][ny] = 1;
                    maap[{nx, ny}] = {a, b};
                    if (grid[nx][ny] == 2)
                        pq.push({x.first + 1, {dist[nx][ny], {nx, ny}}});
                    else
                        pq.push({x.first, {dist[nx][ny], {nx, ny}}});
                }
            }
        }
    }
    return {1, {1, {}}};
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    vector<vector<ll>> value(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> value[i][j];
    //now start bfs from every possible left column
    pair<ll, pair<ll, vpii>> pr{INT_MAX, {INT_MAX, {}}};
    for (int i = 0; i < n; i++)
    {
        auto x = bfs(i, 0, grid, value);
        //cout << x.first << " " << x.second << endl;
        if (x.first < pr.first)
            pr = x;
        else if (x.first == pr.first and x.second.first < pr.second.first)
            pr = x;
    }
    rev(pr.second.second);
    for (auto x : pr.second.second)
        cout << x.first << " " << x.second << endl;
}
int main()
{

    FAST_IO
    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}