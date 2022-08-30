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
void tbuild(vi &hotel, int ns, int ne, int tnode, vi &stree)
{
    if (ns == ne)
    {
        stree[tnode] = hotel[ns];
        return;
    }
    ll mid = (ns + ne) / 2;
    tbuild(hotel, ns, mid, 2 * tnode, stree);
    tbuild(hotel, mid + 1, ne, 2 * tnode + 1, stree);
    stree[tnode] = stree[2 * tnode] + stree[2 * tnode + 1];
}
ll query(vi &stree, int ns, int ne, int tnode, int lreq, int rreq)
{

    if (lreq > ne || rreq < ns)
        return 0;
    // cout << "lreq " << ns << " rreq " << ne << endl;
    if (ns >= lreq and ne <= rreq)
        return stree[tnode];
    ll mid = (ns + ne) / 2;

    return query(stree, ns, mid, 2 * tnode, lreq, rreq) + query(stree, mid + 1, ne, 2 * tnode + 1, lreq, rreq);
}
void upd(vi &stree, int ns, int ne, int tnode, int i, int diff)
{
    if (i > ne || i < ns)
        return;
    stree[tnode] += diff;
    if (ns != ne)
    {
        int mid = (ns + ne) / 2;
        upd(stree, ns, mid, 2 * tnode, i, diff);
        upd(stree, mid + 1, ne, 2 * tnode + 1, i, diff);
    }
}
void solve()
{
    ll n;
    cin >> n;
    vi v(n + 1), isp(n + 1, 1), stree(4 * n + 2);
    isp[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    tbuild(isp, 1, n, 1, stree);
    ll u = n;
    while (u--)
    {
        ll k;
        cin >> k;
        ll lo = 1, hi = n;
        while (lo <= hi)
        {
            ll mid = (hi + lo) / 2;
            // find how many elements are there till mid
            ll f = query(stree, 1, n, 1, 1, mid);
            // cout << "k is " << mid << endl;

            if (f < k)
                lo = mid + 1;
            else if (f > k)
                hi = mid - 1;
            else
            {
                if (isp[mid])
                {
                    lo = mid;
                    break;
                }
                else
                    hi = mid - 1;
            }
        }
        // cout << "lo is " << lo << endl;
        isp[lo] = 0;
        cout << v[lo] << " ";
        upd(stree, 1, n, 1, lo, -1);
    }
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