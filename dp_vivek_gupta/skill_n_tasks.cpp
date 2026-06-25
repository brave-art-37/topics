/*
 Given n tasks, each gives s[i] skill to you and requires t[i] time, given you can do max k tasks and have max T time, find max skill you can gain
 */

#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1001;
int n,k,T;
int t[MAXN];
int s[MAXN];
int chosen=0, tme=0;

int recurr(int r){ //returns best choice from [r ... n-1] tasks left
               
  if(r==n){ //all tasks have been decided
    return 0;
  }

  int ans=0;

  //not choose task r
  ans = max(ans, recurr(r+1));

  //choose task r
  chosen++, tme+=t[r];
  if(chosen<=k && tme<=T){ //look ahead 
    ans=max(ans, s[r]+recurr(r+1));
  }

  //backtrack
  chosen--, tme-=t[r];

  return ans;
}

void solve(){
  cin>>n>>T>>k;
  for(int i=0;i<n;i++){
    cin>>s[i]>>t[i];
  }
  cout<<recurr(0)<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

