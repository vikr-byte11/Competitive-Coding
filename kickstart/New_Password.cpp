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
#define FAST_IO            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define ip(v)       \
  for (auto &x : v) \
  cin >> x
#define op(v)         \
  for (auto x : v)    \
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
typedef map<int, int> mii;

const int md = 1e9 + 7;
// &*!=
// ()@
//Vikram1234@
void solve()
{
  static int bh = 0;
  bh++;
  bool f1=0,f2=0,f3=0,f4=0,f5=0;
  ll n;cin>>n;
  string s;cin>>s;
  for(auto x:s)
  {
      if(x-'a'>=0 and x-'a'<=25)
       f1=true;//small
      if(x-'A'>=0 and x-'A'<=25)
       f2=true;//capital
       if(x-'0'>=0 and x-'0'<=9)
        f3=true;
       if(x=='#'||x=='@'||x=='*'||x=='&')
        f4=true;
  }
  if(!f1)
   s+='a';
   
  if(!f2)
   s+='A';
   
  if(!f3)
   s+='9';
   
  if(!f4)
   s+='#';
 if(s.size()<7)
 {
     while(s.size()<7)
      s+='a';
 }
  cout << "Case #" << bh << ": "
       << s << endl;
}
int main()
{

  FAST_IO
  ll t = 1;
  cin>>t;

  while (t--)
  {
    solve();
  }
  return 0;
}