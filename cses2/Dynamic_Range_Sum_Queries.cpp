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

const int Mod = 1e9 + 2;
// &*!=
// ()@
//Vikram1234@
void build(int l,int hi,int tnode,vi &v,vi &seg)
{
    if(l==hi)
    {
        seg[tnode]=v[l];
        return;
    }
    int mid=l+(hi-l)/2;
    build(l,mid,2*tnode+1,v,seg);
    build(mid+1,hi,2*tnode+2,v,seg);
    seg[tnode]=seg[2*tnode+1]+seg[2*tnode+2];
}
ll getsum(int nl,int nh,int tnode,int lreq,int rreq,vi &seg)
{
    //3 cases:
    //1. no overlap: return 0
    //2. total overlap: return value
    //3. partial overlap : recursion
    if(nl>rreq||nh<lreq)
    return 0;
    if(lreq<=nl and rreq>=nh)
     return seg[tnode];
    int mid= nl+(nh-nl)/2;
    ll op1=getsum(nl,mid,2*tnode+1,lreq,rreq,seg);
    ll op2=getsum(mid+1,nh,2*tnode+2,lreq,rreq,seg);
    return op1+op2;
}
void upd(int nl,int nh,int tnode,int idx,vi &seg,vi &v,int diff)
{
    if(idx<nl||idx>nh)
    return;
    
    seg[tnode]+=diff;
    if(nl==nh)
    return;
    int mid=nl+(nh-nl)/2;
    upd(nl,mid,2*tnode+1,idx,seg,v,diff);
    upd(mid+1,nh,2*tnode+2,idx,seg,v,diff);
}
void solve()
{
    ll n,q;cin>>n>>q;
    vi v(n);
    ip(v);
    vi seg(4*n);
    build(0,n-1,0,v,seg);
    while(q--)
    {
        int type,x,y;cin>>type>>x>>y;
        x--;
        if(type==2)
        {
            y--;
            cout<<getsum(0,n-1,0,x,y,seg)<<endl;
        }
        else
        {
            //update
            int diff=y-v[x];
            v[x]=y;
            upd(0,n-1,0,x,seg,v,diff);
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