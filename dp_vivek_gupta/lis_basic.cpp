/*
 Given arr of n elts, find len of LIS
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
int arr[MAXN];
int dp[MAXN];

int recurr(int r){//returns len of LIS ending at index r
                  
  dp[r]=1; //subseqn including only index r

  for(int l=1;l<r;l++){
    if(arr[l]>=arr[r]) continue;
    dp[r]=max(dp[r],1+dp[l]); //extend LIS ending at index l
  }

  return dp[r];
}

void solve(){
  cin>>n;
  for(int i=1;i<n+1;i++) cin>>arr[i];
  memset(dp,0,sizeof(dp));
  int ans=0;
  for(int i=1;i<n+1;i++){
    ans=max(ans,recurr(i));
  }
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
