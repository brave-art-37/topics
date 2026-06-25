/*
 Given a set of nos, find no to ways to distribute it into two disjoint and exhaustive sets A,B s.t. sum(A)%sum(B)==0
 */
#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1001;
int n, sum=0;
int arr[MAXN];
int dp[MAXN][MAXN];
bool done[MAXN][MAXN];

int recurr(int r, int a){//returns #ways to form (A,B) s.t. elts from arr[1 ... r-1] have been picked for A with sum(A)=a

  //pruning

  //base case
  if(r==n+1) return (sum!=a && abs(a)%abs(sum-a)==0);

  //cache
  if(done[r][a]) return dp[r][a];

  //transition
  dp[r][a]=recurr(r+1,a+arr[r])+recurr(r+1,a); //A now contains arr[r] or not
  done[r][a]=1;
  return dp[r][a];
}

void solve(){
  cin>>n;
  for(int i=1;i<n+1;i++) { cin>>arr[i]; sum+=arr[i]; }
  cout<<recurr(1,0)<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
