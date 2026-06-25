/*
 Given n +ve nos and q queries, find if there is a subset of them with sum exactly k for each query
 */
#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1001;
int n, q, k;
int arr[MAXN];
int dp[MAXN][MAXN]; //dp[r][sum]=1 iff sum can be formed by elts from [r ... n] in arr

int recurr(int r, int sum) { //decides if sum can be formed from elts [r ... n] in arr

  //pruning
  if(sum<0) return 0; //can't have -ve sum

  //base case
  if(r==n+1) return (sum==0); //empty set only 0 sum possible

  //cache
  if(dp[r][sum]!=-1) return dp[r][sum]; //have already calc val

  //transition
  dp[r][sum] = (recurr(r+1,sum-arr[r]) || recurr(r+1,sum)); //either use arr[r] or not
  return dp[r][sum];
}

//rechecking for printing
void printset(int r, int sum){
  if(r==n+1) return; 

  if(recurr(r+1,sum)==1) printset(r+1,sum); //subset does NOT include arr[r]
  else { cout<<arr[r]<<' ';printset(r+1,sum-arr[r]); } //subset includes arr[r]
}

void solve(){
  cin>>n;
  for(int i=1;i<n+1;i++) cin>>arr[i];
  memset(dp,-1,sizeof(dp));
  cin>>q;
  while(q--){
    cin>>k;
    if(recurr(1,k)==0){
      cout<<"NO\n";
    }
    else{
      cout<<"YES\n";
      printset(1,k);
      cout<<"\n";
    }
  }
   // note that we do NOT need to refresh dp arr for diff values of k in each query as once our dp arr computation does not use it
   
   // dp[r][sum] only cares if sum can be formed from elts [r ... n]

   // we printed by rechecking, we could also have stored backptrs
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
