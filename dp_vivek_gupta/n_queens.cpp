/*
 Find #ways to place n queens in a nxn board so that no 2 queens attack each other
 */

#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1001;
int n;
int queen[MAXN];
int diag1[MAXN];
int diag2[MAXN];
int col[MAXN];
int ans=0;

void recurr(int r){ //returns #ways to place queens in rows [r ... n-1] if earlier rows are all filled

  if(r==n){ //all the queens have been placed successfully
    ans++;
    return;
  }

  for(int c=0; c<n; c++){ //check all possible column vals
    if(col[c] || diag1[r+c] || diag2[n-r+c]) continue; //another queen attack this cell

    queen[r]=c, col[c]=1, diag1[r+c]=1, diag2[n-r+c]=1; //place queen
    recurr(r+1); //check ahead
    queen[r]=-1, col[c]=0, diag1[r+c]=0, diag2[n-r+c]=0; //backtrack;

     }
}

void solve(){
  memset(queen, -1, sizeof(queen));
  cin>>n;
  recurr(0);
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

