/*
 Given arr of n nos, find and print LIS using Parting Sort in O(n log n)
 */
#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<int> top;
  map<int,int> backptr;
  for(int i=0;i<n;i++){
    int tmp;cin>>tmp;
    auto it=lower_bound(top.begin(),top.end(),tmp); //first pile after the pile whose top card can be extended by tmp
    int idx=(it-top.begin());
    if(it==top.end()) top.push_back(tmp); //if extending last pile
    else top[idx]=tmp;

    if(idx==0) backptr[tmp]=-1; //to store val which was extended by tmp
    else backptr[tmp]=top[idx-1];

    //for(int num:top) cerr<<num<<' ';cerr<<"\n";
  }
  cout<<top.size()<<"\n";
  int start=top.back();
  while(start!=-1){
    cout<<start<<' ';
    start=backptr[start];
  }
  cout<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
