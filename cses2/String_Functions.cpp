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
ll z[2000005];
ll pre[2000005];
void k_mp(string s)
{
    ll n = s.length();
    pre[0] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int j = pre[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pre[j - 1];
        if (s[i] == s[j])
            j++;
        pre[i] = j;
    }
}
void z_f(string s)
{
    ll n = s.length();
    for (ll i = 1, l = 0, r = 0; i < s.length(); i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n and s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}
void solve()
{
    string s;
    cin >> s;
    k_mp(s);
    z_f(s);
    for (int i = 0; i < s.length(); i++)
        cout << z[i] << " ";
    cout << endl;
    for (int i = 0; i < s.length(); i++)
        cout << pre[i] << " ";
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