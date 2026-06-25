/*
 Given a pool of n chips, 2 players can one by one take out any #chips in powers of 2. First person to NOT be able to make a move loses. Find if player playing first move can win.
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
int dp[MAXN];

int recurr(int n){//returns 1 if player making move with n chips on board can win

  //pruning

  //base case
  if(n==0) return 0;

  //cache
  if(dp[n]!=-1) return dp[n];

  //transition
  dp[n]=0;
  int x=1;
  while(x<=n && dp[n]==0){
    dp[n]|=(recurr(n-x)==0);
    x<<=1;
  }
  return dp[n];
}

void solve(){
  cin>>n;
  memset(dp,-1,sizeof(dp));
  cout<<recurr(n)<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

