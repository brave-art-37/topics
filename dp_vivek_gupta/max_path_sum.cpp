/*
 Given a nxn grid on nos, find path with max sum from (1,1) to (n,n)
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
int arr[MAXN][MAXN];
int dp[MAXN][MAXN];
bool calc[MAXN][MAXN]; //to denote if val has been calculated earlier or not

int recurr(int r, int c){ //max path sum from (1,1) to (r,c)

  if(r==0 || c==0) return INT_MIN;

  if(calc[r][c]) return dp[r][c];

  dp[r][c]=arr[r][c];
  dp[r][c]+=max(recurr(r-1,c), recurr(r,c-1));
  calc[r][c]=1;
  return dp[r][c];
}

void printset(int r, int c, int ans){
  cout<<"("<<r<<", "<<c<<") ";
  if(r-1>0 && dp[r-1][c]==ans-arr[r][c]) printset(r-1,c, ans-arr[r][c]);
  else if(c-1>0 && dp[r][c-1]==ans-arr[r][c]) printset(r,c-1, ans-arr[r][c]);
  return;
}

void solve(){
  cin>>n;
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){
      cin>>arr[i][j];
      calc[r][c]=0;
    }
  }
  dp[1][1]=arr[1][1]; calc[1][1]=1;
  int ans=recurr(n,n);
  cout<<ans<<"\n";
  printset(n,n,ans);

  //note that we have to use the calc arr to check if dp[r][c] has been calculated earlier because it may happen that the sum of path = -1
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
