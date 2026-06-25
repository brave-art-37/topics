/*
 Find #binary strings of len n which do NOT have "0100" as - a) subsequence  b) substring
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
int dp_seqn[MAXN][5];
int dp_str[MAXN][5];

//note that the solution for subsequence does NOT depend on the original string => answer is same for strings of same len!
int recurr_seqn(int r, int match){//returns #ways to add suffix to a string of len already r given a certain subseqn is already present earlier
                                  //match = 0:"", 1:"0", 2:"01", 3:"010", 4:"0100"

  //pruning
  if(match==4) return 0;

  //base case
  if(r==n) return 1;

  //cache
  if(dp_seqn[r][match]!=-1) return dp_seqn[r][match];

  //transition
  dp_seqn[r][match]=recurr_seqn(r+1,match)+recurr_seqn(r+1,match+1); //introducing correct char in order gives match+1 branch

  return dp_seqn[r][match];
}


//these state transitions are the "longest suffix of given prefix" as in KMP alg
int recurr_str(int r, int state){//returns #ways to add suffix to a string of len already r given a certain substring is present at the end
                                  //state = 0:"", 1:"0", 2:"01", 3:"010", 4:"0100"
  //pruning
  if(state==4) return 0;
  
  //base case
  if(r==n) return 1;

  //cache
  if(dp_str[r][state]!=-1) return dp_str[r][state];

  //transition
  int ans=0;
  if(state==0) ans+=recurr_str(r+1,0)+recurr_str(r+1,1);
  else if(state==1) ans+=recurr_str(r+1,1)+recurr_str(r+1,2);
  else if(state==2) ans+=recurr_str(r+1,0)+recurr_str(r+1,3);
  else if(state==3) ans+=recurr_str(r+1,2)+recurr_str(r+1,4);
  return dp_str[r][state]=ans;
}

void solve(){
  cin>>n;
  memset(dp_seqn,-1,sizeof(dp_seqn));
  memset(dp_str,-1,sizeof(dp_str));
  cout<<recurr_seqn(0,0)<<"\n";
  cout<<recurr_str(0,0)<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

