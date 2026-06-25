/*
 Given a rod which can be broken at n points, find the min cost of doing n-1 cuts if cost of each cut is the len of rod being cut
 */
#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=101;
int n;
int arr[MAXN];
int dp[MAXN][MAXN];

int recurr(int l, int r){ //min cost of cutting rod arr[l ... r] completely

  //pruning

  //base case
  if(r<=l+1) return 0;

  //cache
  if(dp[l][r]!=-1) return dp[l][r];

  //transition
  dp[l][r]=arr[r]-arr[l];
  int mini=INT_MAX;
  for(int i=l+1;i<r;i++){
    mini=min(mini, recurr(l,i)+recurr(i,r));
  }
  dp[l][r]+=mini;
  return dp[l][r];
}

void solve(){
  memset(dp,-1,sizeof(dp));
  cin>>n;
  for(int i=1;i<n+1;i++) cin>>arr[i];
  cout<<recurr(1,n)<<"\n";
  //read Knuth Optimisation for this LR/Interval/Partition DP
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

