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
#define op(v)        \
    for (auto x : v) \
    cout << x << " "; \
	 cout<<endl
#define tr(v) for (auto x : v)
#define srt(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define clr(x) memset(x,0, sizeof(x))

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef map<int, int> mii;

const int Mod = 1e9 + 7;
void fun(int lo,int hi,int tnode, vi &v,vector<pair<ll,ll>> &seg)
{
  if(lo==hi)
  {
    seg[tnode].first=v[lo];
    seg[tnode].second=0;
    return;
  }
  int mid=lo+(hi-lo)/2;
  fun(lo,mid,2*tnode+1,v,seg);
  fun(mid+1,hi,2*tnode+2,v,seg);
  seg[tnode].first=seg[2*tnode+1].first+seg[2*tnode+2].first;
}
void upd(int nl,int nr,int tnode,vector<pair<ll,ll>> &seg,int lreq,int rreq,int u)
{
  if(nl>rreq||nr<lreq)
  return;
  if(nl>=lreq and nr<=rreq)
  {
    seg[tnode].first+=(nr-nl+1)*u;
    seg[tnode].second+=u;//below updates
    return;
  }
  int mid=nl+(nr-nl)/2;
  upd(nl,mid,2*tnode+1,seg,lreq,rreq,u);
  upd(mid+1,nr,2*tnode+2,seg,lreq,rreq,u);
}
ll qry(int lo,int hi,int node,vector<pair<ll,ll>> &seg,int i,ll carry)
{
   if(i<lo||i>hi)
    return 0;
    if(i<=lo and hi<=i)
     return seg[node].first+carry;
    int mid=lo+(hi-lo)/2;
    return qry(lo,mid,2*node+1,seg,i,carry+seg[node].second)+qry(mid+1,hi,2*node+2,seg,i,carry+seg[node].second);
}
void solve()
{
  ll n,q;cin>>n>>q;
  vi v(n);
  ip(v);
  vector<pair<ll,ll>> seg(4*n+4);
  fun(0,n-1,0,v,seg);
  while(q--)
  {
    ll type;cin>>type;
    if(type==1)
    {
      int b,x,y;cin>>b>>x>>y;
      b--,x--;
     upd(0,n-1,0,seg,b,x,y);
    }
    else
    {
      int idx;cin>>idx;
      idx--;
      cout<<qry(0,n-1,0,seg,idx,0LL)<<endl;
    }
  }
}
int main()
{ 

	FAST_IO
	ll t=1;
	//cin>>t;

	while(t--){
		solve();
  }
	return 0;
}