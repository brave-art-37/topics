/*
 Given 2 arrays, find their longest common subsequence (LCS)
 */
#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1001;
int n,m;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int recurr(int i, int j ,int k){ //LCS of a[i ... n] and b[j ... m]
                          
  //pruning

  //base case
  if(i==n+1 || j==m+1) return 0; //reached end of arr, no elt left to match

  //cache
  if(dp[i][j]!=-1) return dp[i][j];

  //transition
  dp[i][j]=0;
  if(a[i]==b[j]) dp[i][j]=max(dp[i][j], 1+recurr(i+1,j+1)); //first elts match
  else dp[i][j]=max({dp[i][j], recurr(i,j+1), recurr(i+1,j)});//discard first elt

  return dp[i][j];
}

void solve(){
  cin>>n>>m;
  memset(dp, -1, sizeof(dp));
  for(int i=1;i<n+1;i++) cin>>a[i];
  for(int i=1;i<m+1;i++) cin>>b[i];
  cout<<recurr(1,1)<<"\n";
  //same logic can be easily extended to 3 arrays
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

